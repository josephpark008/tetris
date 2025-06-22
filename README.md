Tetris coded in C++

Coded Tetris as my first C++ project. I wanted to give myself a challenge to learn to code in C++, and rendering in SMFL, and basic game logic.

Create grid
	- Use adjacency matrix

Create four different block formations
	- S, T, square, line


Point system
	- Keep track of points 
	- Earn points for each row cleared
	- A row is cleared when all squares of that row are filled with a block

Game end
	- When a block is tacked above the top line

Block queue
	- There will be a queue that holds 3 blocks 
	- The user can see the next block in queue 
	- Block formation added to queue are randomized 

Block fall rate
	- Begin at 0.5 sec/square
	- Bonus: increase rate as points increase to make it harder
 
User control
	- User will be able to translate block left and right, and rotate 
	- Three buttons (left, right, rotate)

Block form rotate logic
	- Block form rotate around center (different for some block types)
	- Center for block
		- S (2 center blocks)
		- Square (can’t rotate, because will always be the same)
		- Line (2 center blocks)
		- T (2 center blocks)

Block stack logic
	- Keep track of the bottom edges of the block
	- If atleast one bottom edge is touching another edge
		- The block is placed immediately 
	- If you try to rotate and the block cannot fit in it will move up a square level until it does fit

Clear level
	- When all squares on a level are filled with a block, clear the level by removing all blocks in that level and moving all blocks above down one level
	- Add however many levels were cleared to point total

Rendering
	- Each 0.5 seconds = new frame
	- Rerender the matrix
	- Pass in current frame/matrix to grid class and create new/updated frame

Design schema

	- Class to create grids (4 params: boolean (round status), matrix, key pressed, falling block)
		- Takes in key pressed and rerenders based on transformation
			- Keys/transformations are: rotate, left, right, down (called internally to move block down every 0.5 sec)
				- Can'tse move left, right, down if another block is in the way (square is taken)
				- If key is rotate then apply transformation to rotate block around 2 center squares (unless if square, don’t do anything)
		- Takes a boolean param to see if a block is falling vs right after a block is placed
			- Refer to Block is Placed segment below
		- Also takes in a 0 (new grid) or a matrix (to update grid)
			- IF matrix: (Block is placed)
				- Check if any levels are completed with block, clear those levels
				- If rows are cleared move everything above that level down
					- Start from bottom up from the lowest level cleared. 
					- While looping from bottom up use a counter to count how many levels cleared. Move active levels above down squares by the counter amount
				- After block is placed, call again and pass in next block in queue
		- Create a top line grid, and if any blocks are stacked above it, game over
		
	- Class to create different block formations
Class to create block queue
