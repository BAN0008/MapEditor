# TODO
- Make sure that MapEditor performs well with massive densely populated maps
- Make a toolbar for switching modes(can be disabled under view menu)
- Make a toolbar or menu for changing grid options
- Change all Object static functions to take an index as a argument rather than a (Object \*)
- Run this file through a markdown linter
- Change function that take coordinates to use QPoint And QRect
- Fix ACTION_REMOVE_MULTIPLE removing more than one object underneath it at a time
- Make sure that ACTION_\*REMOVE\*'s remove the top object first
- Add Status Bar that shows the coordinates of the mouse as well as the coordinates divided by the Grid Size


# Issues
- MainEditor not updating when Object::selectionChange is called
- objectList causing all selection to be cleared unless
  control is being held(see below for potential solutions)
	- Change selection mode when selecting objects from MainEditor
	- Change objectList selection with QItemSelectionModel(Likely the best solution)
- Holding shift and scrolling to scroll horizontally isn't working for objectList
- Bindings involving Alt + Mouse Button are broken because this is a common binding for window managers
- MainWindow::key\*Event functions not performing as intended likely due to focus(See QEvent::ignore() and setFocusPolicy() for a potential solution)


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
- Confirm Dialog for removing objects with large parameters(Enabled by default)
- Save history(Enabled by default)

## Ideas
- Powder toy like zoom to enhance precision???
- Multiple Grids with different sizes and colours???

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
	- View
		- Show mode toolbar(Checkbox)
		
- Object Property Editor


# Global Controls
| Action           | Binding             |
| ---------------- | ------------------- |
| Add Mode         | Q                   | Done
| Select Mode      | W                   | Done
| Remove Mode      | E                   | Done
| Undo             | Control + Z         |
| Redo             | Control + Shift + Z |
| Select All       | Control + A         | Done
| Deselect All     | Control + D         | Done
| Delete Selection | Delete              | Done
| Move Selection   | Right Click + Drag  | (what about context menus???)
| Pan Camera       | Middle Mouse + Drag |
| Toggle Grid Snap | Control + G         |

All global controls should be changeable



# Modes
## Add Mode
### Controls
| Action       | Binding              |
| ------------ | -------------------- |
| Add Single   | Left Click           | Done
| Add Multiple | Shift + Left Click   | Done(could be refined so that there are no gaps between placed objects no matter the speed)
| Add Fill     | Alt + Left Click     | (Needs to change, see issues)

The last object created by Add Single will be selected


## Select Mode
### Controls
| Action          | Binding             |
| --------------- | ------------------- |
| Select Single   | Left Click          | Done
| Selection Box   | Left Click + Drag   |
| Magic Select    | Alt + Left Click    | (Needs to change, see issues)
| Keep Selection  | Control             |


## Remove Mode
### Controls
| Action          | Binding            |
| --------------- | ------------------ |
| Remove Single   | Left Click         | Done
| Remove Multiple | Shift + Left Click | Done

# Grid Options
- Toolbar
- Context Menu
- Dialog
- Editable Tabed Table
- 