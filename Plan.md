# TODO
- Make sure that MapEditor performs well with massive densely populated maps

# Issues
- MainEditor not updating when Object::selectionChange is called
- objectList causing all selection to be cleared unless
  control is being held(see below for potential solutions)
	- Change selection mode when selecting objects from MainEditor
	- Change objectList selection with QItemSelectionModel(Likely the best solution)
- Holding shift and scrolling for horizontal scrolling isn't working for objectList


# Actions
### Create Objects
- Place Single Object
- Place Multiple Objects
- Fill Tool(Option to collide with other layers)

#### Options
- Replace Objects
- Check For Collision(Option to collide with other layers)

### Select Objects
- Magic Select
- Free Select
- Box Select
- Individual Select

#### Actions
- Move Selected Objects

### Remove Objects
- Remove Single Object
- Remove Multiple Objects

#### Options
Confirm Dialog for deleting objects with large parameters

## Global
- Powder toy like zoom to enhance precision???

# UI
## MainWindow
- MainEditor
- Object List
- Object Selector
- History
- Layer Selector
- Status Bar
- Menu Bar
	- File
		- Save
		- Save As
		- Open
		- Exit
	- Edit
		- Copy
		- Cut
		- Paste
		
- Object Property Editor
