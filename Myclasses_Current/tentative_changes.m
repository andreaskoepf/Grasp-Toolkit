% Tentative Changes
# General
        ! Add Preview GUI to display a newly registered model
            
! 1 - Use the @directory format for all classes
        !-   Separate Methods in their own mfile
! 2 - Create Link Class in order to have Phalanx inherit from it
        
! 3 - Redifine the way in which joint types are defined

! 4 - In the finger class make the base a separate object from the rest
        !-  figer phalanges
        
! 5 - Create Posture Class
        !- Add corresponding methods for finger and hand class to 
        
! 6 - Create Simple environment class
        !- Look up convhulln
        
! 7 - Create Affine Transform Class

! 8 - add method that allows to register and clear new object types.
        !- if possible, implement this functionality in the class "Toolkit"
        
! 9 - give the template functionality to the "Toolkit" Class

! 10- create elipsoid class and prevent Sphere class from being resized unevenly

! 11- add finger class
!   -   provide dependent properties method signatures for contact points 
!       other characteristics.

            
# Solid Class
!Done    !- separate the loading file from the constructor
    !- add boolean to determine when should the axis be resized according to 
    !  the Axis Limits Property.
    !- Rename AxisLimit as BoundingBox ( the need for this is to be evaluated first)
    !- Add set methods for all mass parameters properties in order to ensure 
    !   that the data is of the right size and dimension.
 !Done   !-  create a loadFieldsFromStruc method
    !- provide method to construct the convex hull of a solid or an array of
    !  Solid objects and return them as a solid object
 !Done   !- change constructor so that a char argument opens a existing model if it exist
    !- or loads the geometric data from a file.

# Template Classes
    !-      Create methods that enable updating the information contain in the
            ! mat files without having to the object entirely
         
    !-      Store the data points,(vertices and faces ) in mat file that
            !stores the entity details

# Toolkit Class
    !-      Write function that generates hierarchical list with the
            ! functions grouped by classes and functionality
    !-      give this class the ability to save new models and register
    !       them under a particular class. generate data file that mantains
    !       new records of existing saved models.
    !-      Add Register Class method
    !-      Allow user to select which model to import whenever multiple 
    !       objects are contained in a  single file
    !-      add register method for finger 
    !-      determine if a separate class "Phalanx" is necessary since the 
    !       objects already possess most of the necessary attributes
    !-      add the inherit data from subclass option in the registerLink 
    !       method
            
# Link Class
    !-      Write function that allows to save changes to a given model template
    
    !-  create a fillFieldsFromStruc method
    
    !-  allow the constructure to load existing models from data structures in data
    !   files and also from structure arrays .  Some verification checking routines
    !   should be added in order to ensure that data is assigned correctly during
    !   object instantiation
    
# KinematicChain
    !-  