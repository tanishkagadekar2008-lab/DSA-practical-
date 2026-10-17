1. Algorithm
Main program
1. Start. Set the playlist (singly linked list) and the player (doubly linked list) to empty.
2. Show the menu and read the choice.
3. Call the function for the chosen operation, then go back to Step 2.
4. If the choice is Exit (0), free all nodes of both lists and stop.
Add Song
1. Singly list: create a node with the song name and set its next = NULL. If the list is empty, make it the head. Otherwise move to the last node and set last->next = new node.
2. Doubly list: create a node with the song name. Set its next = NULL and prev = tail. If tail exists, set tail->next = new node, otherwise set head = new node. Then set tail = new node.
3. If nothing is playing yet (current is NULL), set current = new node.
Delete Song
1. Singly list: if the first node holds the song, move head to the next node and free the old head. Otherwise keep prev and curr, move forward until curr holds the song, then set prev->next = curr->next and free curr.
2. If the song is not found, report not found and stop.
3. Doubly list: find the node, then link its previous and next nodes to each other (update head or tail if it was the first or last node).
4. If the deleted node was the current song, move current to its next node, or to its previous node if there is no next node.
5. Free the node.
Search Song
1. Start at the head of the singly list with position = 1.
2. While the node is not NULL: if the name matches, print the position and stop; otherwise move to the next node and add 1 to the position.
3. If the end is reached, report not found.
Show Playlist
1. If the singly list is empty, report that the playlist is empty and stop.
2. Start at head and print each song with its number, following the next pointers, until NULL.
Next Song / Previous Song
1. If current is NULL, report that the playlist is empty and stop.
2. Next: if current->next is NULL, report that this is the last song. Otherwise set current = current->next and print it.
3. Previous: if current->prev is NULL, report that this is the first song. Otherwise set current = current->prev and print it.
Now Playing
1. If current is NULL, report that no song is playing. Otherwise print the song in current.
Show Reverse
1. If the doubly list is empty, report that the playlist is empty and stop.
2. Start at tail and print each song with its number, following the prev pointers, until NULL.

 
