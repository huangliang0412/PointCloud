#include "kdtree.h"

//const int K = 15;

PointCloudT::Ptr KdTree(PointCloudT::Ptr &original_cloud, int K)
{
    if (K == 0)    //if K is 0 , we don't deal it
        return original_cloud;

    else {
        /*build a kdtree, pointcloud data will be
     *import the kdtree
     */
        pcl::KdTreeFLANN<PointT> SimplifyKdtree;
        SimplifyKdtree.setInputCloud (original_cloud);

        /* build a vector to record the pointcloud's points
     * is or not is be visited, if a point is marked false
     * this point will be save, if a point is marked true
     * this point will be disappear
     */
        std::vector<bool>cloudpoints_visited(original_cloud->points.size(), false);

        for (size_t i = 0; i < original_cloud->points.size(); ++i)
        {
            if (cloudpoints_visited[i] == true)
                continue;

            std::vector<int> pointIdxNKNSearch(K);   // this vector save the points that the shortest K points
            std::vector<float> pointNKNSquaredDistance(K); // this vector save the shortest K points' distance

            if (SimplifyKdtree.nearestKSearch (original_cloud->points[i], K, pointIdxNKNSearch, pointNKNSquaredDistance) > 0)
            {
                for (size_t j = 0; j < pointIdxNKNSearch.size(); ++j)
                {
                    /* in order to all points disappear, so if a point's id
                  * less than i, I would save it. OtherWise discard it
                  */
                    if (i < pointIdxNKNSearch[j])
                        cloudpoints_visited[pointIdxNKNSearch[j]] = true;
                }
            }
        }

        /* I would build a new pointcloud that is simplified */
        PointCloudT::Ptr tidy_cloud(new PointCloudT);

        for (size_t i = 0; i < cloudpoints_visited.size(); ++i)
        {
            if (cloudpoints_visited[i] == true)
                continue;
            tidy_cloud->push_back(original_cloud->points[i]);
        }

        return tidy_cloud;
    }
}
