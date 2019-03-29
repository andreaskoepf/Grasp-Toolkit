% changes
# General
    !- Added class directories to Cube, Solid, Sphere and Toolkit
            
# Solid Class
    !- Changed resized method
    !- Added Cube and Sphere
    !- Added help comments on several member functions
    !- Added mass parameters
    !- Added quaternion, equivalent angle axis representation and Transform
    !  equivalent conversion static method.
    !- added transform property
    !- added world tranform dependent property.

# Template Classes


# Toolkit Class
    !-      Added Class
    !-      Added Root to Toolkit
    !-      Added Static method loadGeometryFromFile
    
# Link Class
    !-      Added Class
    !-      Overloaded update method
    !-      Added NextObject property
    !-      Updated update method in order to update the object that has 
    !       its reference assigned to NextObject.
    !-      Added Copy Constructor and provided a type char input argument
    !       and a struct input argument
    !-      added loadFieldFromStruct method
    
# KinematicChain Class
    !-      Added Class
    !       added dependent JointValues, JointLimits and JointOffsets
    !-      set dependent DH property set access to protected.
    !-      added the dependent properties JointValues, JointOffset, 
    !       JointLimits
    !-      added DOF properties with dependent attribute set to false 
    !       since this property is called many times then it is preferred 
    !       to store it rather than calculate it on every call.
         

    