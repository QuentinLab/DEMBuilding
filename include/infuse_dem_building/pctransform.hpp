#ifndef _PCTRANSFORM_HPP_
#define _PCTRANSFORM_HPP_

#include <infuse_dem_building/common.hpp>
#include <Eigen/Geometry>

namespace atlaas {

class cloudTransform
{
    protected:

        /* Inputs and outputs of the DFN */
        points                  pointCloud; 
        matrix                  tfSensor2World;

        /* Frames names */

        std::string             robotFrame;
        std::string             fixedFrame;

        /* Internal variables */
        
        Eigen::Quaterniond      rotationSensor2Robot;   // Store rotation from sensor frame to rover body frame
        Eigen::Matrix4d         transformSensor2Robot;  // Store transform from sensor frame to rover body frame

        Eigen::Quaterniond      rotationRobot2World;    // Store rotation from rover body frame to fixed frame (Local terrain frame)
        Eigen::Matrix4d         transformRobot2World;   // Store transform from rover body frame to fixed frame (Local terrain frame)

        Eigen::Matrix4d         transformSensor2World;  // Store transform from sensor frame to fixed frame (Local Terrain frame)

        /* Test variabes */

        int                     cloudSize;




    public:
        cloudTransform();
        ~cloudTransform();

        virtual void clean_up();

        bool transform_pointCloud(/*pointCloud*/);

        /* Setters and getters for DEBUG */

        bool set_transform(matrix tfToSet)
        {
            tfSensor2World=tfToSet;
            return true;
        };

        matrix get_transform()
        {
            return tfSensor2World;
        };

        bool set_pointCloud(points pcToSet,int size)
        {
            pointCloud=pcToSet;
            cloudSize = size;
            return true;
        };

        points get_pointCloud()
        {
            return pointCloud;
        };

        int get_cloudSize()
        {
            return cloudSize;
        }

        std::string getFixedFrame()
        {
            return fixedFrame;
        }
};

};


#endif
