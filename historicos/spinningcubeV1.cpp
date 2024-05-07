/******************************************************
 * Copyright (c) 2024 Diego Antonio López López       *
 *               diego.a.lopez@udc.es                 *
 *               Alejandro Rodríguez Vaquero          *
 *               a.vaquero@udc.es                     *
 *                                                    *
 * This code is for the IGM course assignment         *
 * in OpenSceneGraph                                  *
 * from the MUEI "Universidade da Coruña"             *
 * to the date 03-04-2024 and is free to use          *
 * and distribute.                                    *
 ******************************************************/

#include <osg/Geode>
#include <osg/Group>
#include <osg/ShapeDrawable>
#include <osgViewer/Viewer>
#include <osg/MatrixTransform>
#include <osg/AnimationPath>
#include <osgGA/KeySwitchMatrixManipulator>
#include <osgGA/TrackballManipulator>

int main(int argc, char** argv) {
    // Create a root node
    osg::ref_ptr<osg::Group> root = new osg::Group;
    
    //Enable Default Light
    osg::ref_ptr<osg::StateSet> ss = root->getOrCreateStateSet();
	ss->setMode(GL_LIGHTING, osg::StateAttribute::ON);
    

    // Create a transform node to displace the cube
    osg::ref_ptr<osg::MatrixTransform> cubeTransform = new osg::MatrixTransform;
    osg::Matrix matrix;
    matrix.makeTranslate(0.0f, -5.0f, 0.0f); // move the cube negative 5 units in the z axis
    cubeTransform->setMatrix(matrix);

    // Create a geode to hold the cube shape
    osg::ref_ptr<osg::Geode> geode = new osg::Geode;
    
    // Create a cube shape
    osg::ref_ptr<osg::Box> box = new osg::Box(osg::Vec3(0, 0, 0), 1.0f);
    osg::ref_ptr<osg::ShapeDrawable> shapeDrawable = new osg::ShapeDrawable(box);

    // Set the color of the cube
    osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array;
    colors->push_back(osg::Vec4(1.0f, 0.0f, 0.0f, 1.0f)); // Red color
    shapeDrawable->setColorArray(colors);
    shapeDrawable->setColorBinding(osg::Geometry::BIND_OVERALL);

    // Add the shape to the geode
    geode->addDrawable(shapeDrawable);

    // Add the geode to the transform node
    cubeTransform->addChild(geode);

    // Add the transform node to the root node
    root->addChild(cubeTransform);

    // Create a rotation animation and orbiting aroung (0.0f, -5.f, 0.0f)
    
    osg::ref_ptr<osg::AnimationPath> rotationAnimation = new osg::AnimationPath;
    rotationAnimation->setLoopMode(osg::AnimationPath::LOOP);
    rotationAnimation->insert(0.0, osg::AnimationPath::ControlPoint(osg::Vec3(4.0f, 0.0f, 0.0f), osg::Quat(0.0, osg::Vec3(1.0, 0.0, 0.0))));
    rotationAnimation->insert(3.0, osg::AnimationPath::ControlPoint(osg::Vec3(0.0f, 4.0f, 0.0f), osg::Quat(osg::PI_2, osg::Vec3(1.0, 1.0, 0.0))));
    rotationAnimation->insert(6.0, osg::AnimationPath::ControlPoint(osg::Vec3(-4.0f, 0.0f, 0.0f), osg::Quat(osg::PI_2, osg::Vec3(0.0, 0.0, 1.0))));
    rotationAnimation->insert(9.0, osg::AnimationPath::ControlPoint(osg::Vec3(0.0f, -4.0f, 0.0f), osg::Quat(osg::PI_2, osg::Vec3(-1.0, -1.0, 0.0))));
    rotationAnimation->insert(12.0, osg::AnimationPath::ControlPoint(osg::Vec3(4.0f, 0.0f, 0.0f), osg::Quat(osg::PI_2, osg::Vec3(0.0, 0.0, -1.0))));
    osg::ref_ptr<osg::AnimationPathCallback> rotationCallback = new osg::AnimationPathCallback(rotationAnimation);

    // Attach rotation animation to the transform node
    cubeTransform->setUpdateCallback(rotationCallback);

    // Create a viewer
    osgViewer::Viewer viewer;
    
    // Set the scene data
    viewer.setSceneData(root);

    // Run the viewer
    return viewer.run();
}
