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



    // Create a transform node to displace the cube
    osg::ref_ptr<osg::MatrixTransform> cubeTransform = new osg::MatrixTransform;
    osg::Matrix matrix;
    matrix.makeTranslate(0.0f, -8.0f, 0.0f); // move the cube negative 5 units in the z axis
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
    rotationAnimation->insert(0.0, osg::AnimationPath::ControlPoint(osg::Vec3(4.0f, 0.0f, 2.0f), osg::Quat(0.0, osg::Vec3(1.0, 0.0, 0.0))));
    rotationAnimation->insert(3.0, osg::AnimationPath::ControlPoint(osg::Vec3(0.0f, 4.0f, 2.0f), osg::Quat(osg::PI_2, osg::Vec3(1.0, 1.0, 0.0))));
    rotationAnimation->insert(6.0, osg::AnimationPath::ControlPoint(osg::Vec3(-4.0f, 0.0f, 2.0f), osg::Quat(osg::PI_2, osg::Vec3(0.0, 0.0, 1.0))));
    rotationAnimation->insert(9.0, osg::AnimationPath::ControlPoint(osg::Vec3(0.0f, -4.0f, 2.0f), osg::Quat(osg::PI_2, osg::Vec3(-1.0, -1.0, 0.0))));
    rotationAnimation->insert(12.0, osg::AnimationPath::ControlPoint(osg::Vec3(4.0f, 0.0f, 2.0f), osg::Quat(osg::PI_2, osg::Vec3(0.0, 0.0, -1.0))));
    osg::ref_ptr<osg::AnimationPathCallback> rotationCallback = new osg::AnimationPathCallback(rotationAnimation);
    
    
    // Attach rotation animation to the transform node
    cubeTransform->setUpdateCallback(rotationCallback);
    
    //Second Cube
    
    // Create a transform node to displace the cube
    osg::ref_ptr<osg::MatrixTransform> cubeTransform2 = new osg::MatrixTransform;
    osg::Matrix matrix2;
    matrix2.makeTranslate(0.0f, -8.0f, 0.0f); // move the cube negative 5 units in the z axis and 2
    cubeTransform2->setMatrix(matrix2);

    // Create a geode to hold the cube shape
    osg::ref_ptr<osg::Geode> geode2 = new osg::Geode;
    
    // Create a cube shape
    osg::ref_ptr<osg::Box> box2 = new osg::Box(osg::Vec3(0, 0, 0), 1.0f);
    osg::ref_ptr<osg::ShapeDrawable> shapeDrawable2 = new osg::ShapeDrawable(box2);

    // Set the color of the cube
    osg::ref_ptr<osg::Vec4Array> colors2 = new osg::Vec4Array;
    colors2->push_back(osg::Vec4(0.0f, 0.0f, 1.0f, 1.0f)); // Blue color
    shapeDrawable2->setColorArray(colors2);
    shapeDrawable2->setColorBinding(osg::Geometry::BIND_OVERALL);

    // Add the shape to the geode
    geode2->addDrawable(shapeDrawable2);

    // Add the geode to the transform node
    cubeTransform2->addChild(geode2);

    // Add the transform node to the root node
    root->addChild(cubeTransform2);
    
    // Second Cube Rotation Animation
    osg::ref_ptr<osg::AnimationPath> rotationAnimation2 = new osg::AnimationPath;
    rotationAnimation2->setLoopMode(osg::AnimationPath::LOOP);
    rotationAnimation2->insert(0.0, osg::AnimationPath::ControlPoint(osg::Vec3(4.0f, 0.0f, -2.0f), osg::Quat(0.0, osg::Vec3(1.0, 0.0, 0.0))));
    rotationAnimation2->insert(3.0, osg::AnimationPath::ControlPoint(osg::Vec3(0.0f, 4.0f, -2.0f), osg::Quat(osg::PI_2, osg::Vec3(1.0, 1.0, 0.0))));
    rotationAnimation2->insert(6.0, osg::AnimationPath::ControlPoint(osg::Vec3(-4.0f, 0.0f, -2.0f), osg::Quat(osg::PI_2, osg::Vec3(0.0, 0.0, 1.0))));
    rotationAnimation2->insert(9.0, osg::AnimationPath::ControlPoint(osg::Vec3(0.0f, -4.0f, -2.0f), osg::Quat(osg::PI_2, osg::Vec3(-1.0, -1.0, 0.0))));
    rotationAnimation2->insert(12.0, osg::AnimationPath::ControlPoint(osg::Vec3(4.0f, 0.0f, -2.0f), osg::Quat(osg::PI_2, osg::Vec3(0.0, 0.0, -1.0))));
	osg::ref_ptr<osg::AnimationPathCallback> rotationCallback2 = new osg::AnimationPathCallback(rotationAnimation2);
    
    // Attach rotation animation to the second transform node
    cubeTransform2->setUpdateCallback(rotationCallback2);
    
    // Create an intermediary node to hold the green cube and light source
    osg::ref_ptr<osg::Group> group = new osg::Group;
    
    
    //Create Light
    // Create a transform node to displace the light
    osg::ref_ptr<osg::MatrixTransform> cubeTransform3 = new osg::MatrixTransform;
    osg::Matrix matrix3;
    matrix3.makeTranslate(0.0f, 0.0f, 0.0f); // Translation for light 
    cubeTransform3->setMatrix(matrix3);

    // Create a geode to hold the small cube representing the light
    osg::ref_ptr<osg::Geode> lightGeode = new osg::Geode;

    // Create a cube shape for the small cube representing the light
    osg::ref_ptr<osg::Box> lightGeometry = new osg::Box(osg::Vec3(0, 0, 0), 0.5f);
    osg::ref_ptr<osg::ShapeDrawable> lightDrawable = new osg::ShapeDrawable(lightGeometry);

    // Set the color of the small cube to vibrant green
    osg::ref_ptr<osg::Vec4Array> lightColor = new osg::Vec4Array;
    lightColor->push_back(osg::Vec4(0.0f, 1.0f, 0.0f, 1.0f)); // Vibrant green color
    lightDrawable->setColorArray(lightColor);
    lightDrawable->setColorBinding(osg::Geometry::BIND_OVERALL);

    // Add the shape to the geode
    lightGeode->addDrawable(lightDrawable);

    
    // Add lighting to the scene
    osg::ref_ptr<osg::LightSource> lightSource = new osg::LightSource;
    osg::ref_ptr<osg::Light> light = new osg::Light;
    light->setLightNum(0);
    light->setPosition(osg::Vec4(0.0f, 0.0f, 0.0f, 1.0f)); // Light at origin
    light->setDiffuse(osg::Vec4(1.0f, 1.0f, 1.0f, 1.0f)); // White light
    lightSource->setLight(light);
    //root->addChild(lightSource);
    //cubeTransform3->addChild(lightSource);
    
    //group->addChild(lightSource);
    
    // Add the group to the transform node
    cubeTransform3->addChild(lightGeode);
    
    root->addChild(cubeTransform3);

	root->addChild(lightSource);
	
    //Enable Default Light
    osg::ref_ptr<osg::StateSet> ss = root->getOrCreateStateSet();
	ss->setMode(GL_LIGHTING, osg::StateAttribute::ON);
	
	//Enable secondary light
	ss->setMode(GL_LIGHT0, osg::StateAttribute::ON);

    // Create a viewer
    osgViewer::Viewer viewer;
    viewer.setSceneData(root);

    // Run the viewer
    return viewer.run();
}

