#include <iostream>
#include <string>
using namespace std;
 
struct SNode {
    string song;
    SNode* next;
};
SNode* sHead = NULL;
 
struct DNode {
    string song;
    DNode* prev;
    DNode* next;
};
DNode* dHead = NULL;
DNode* dTail = NULL;
DNode* current = NULL;
 
void addToPlaylist(string song) {
    SNode* n = new SNode();
    n->song = song;
    n->next = NULL;
    if (sHead == NULL) {
        sHead = n;
    } else {
        SNode* temp = sHead;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = n;
    }
}
 
void addToPlayer(string song) {
    DNode* n = new DNode();
    n->song = song;
    n->next = NULL;
    n->prev = dTail;
    if (dTail != NULL)
        dTail->next = n;
    else
        dHead = n;
    dTail = n;
    if (current == NULL)
        current = n;
}
 
void addSong(string song) {
    addToPlaylist(song);
    addToPlayer(song);
    cout << "Added: " << song << endl;
}
 
bool removeFromPlaylist(string song) {
    if (sHead == NULL) return false;
    if (sHead->song == song) {
        SNode* temp = sHead;
        sHead = sHead->next;
        delete temp;
        return true;
    }
    SNode* prev = sHead;
    SNode* curr = sHead->next;
    while (curr != NULL && curr->song != song) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) return false;
    prev->next = curr->next;
    delete curr;
    return true;
}
 
void removeFromPlayer(string song) {
    DNode* temp = dHead;
    while (temp != NULL && temp->song != song)
        temp = temp->next;
    if (temp == NULL) return;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        dHead = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    else
        dTail = temp->prev;
    if (current == temp) {
        if (temp->next != NULL) current = temp->next;
        else current = temp->prev;
    }
    delete temp;
}
 
void deleteSong(string song) {
    if (!removeFromPlaylist(song)) {
        cout << song << " not found." << endl;
        return;
    }
    removeFromPlayer(song);
    cout << "Deleted: " << song << endl;
}
 
void searchSong(string song) {
    SNode* temp = sHead;
    int pos = 1;
    while (temp != NULL) {
        if (temp->song == song) {
            cout << song << " found at position " << pos << "." << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << song << " not found." << endl;
}
 
void displayPlaylist() {
    if (sHead == NULL) {
        cout << "Playlist is empty." << endl;
        return;
    }
    cout << "--- Playlist ---" << endl;
    SNode* temp = sHead;
    int i = 1;
    while (temp != NULL) {
        cout << i << ". " << temp->song << endl;
        temp = temp->next;
        i++;
    }
}
 
void nextSong() {
    if (current == NULL) {
        cout << "Playlist is empty." << endl;
    } else if (current->next == NULL) {
        cout << "Already at the last song: " << current->song << endl;
    } else {
        current = current->next;
        cout << "Now playing: " << current->song << endl;
    }
}
 
void prevSong() {
    if (current == NULL) {
        cout << "Playlist is empty." << endl;
    } else if (current->prev == NULL) {
        cout << "Already at the first song: " << current->song << endl;
    } else {
        current = current->prev;
        cout << "Now playing: " << current->song << endl;
    }
}
 
void nowPlaying() {
    if (current == NULL)
        cout << "No song is playing." << endl;
    else
        cout << "Now playing: " << current->song << endl;
}
 
void displayReverse() {
    if (dTail == NULL) {
        cout << "Playlist is empty." << endl;
        return;
    }
    cout << "--- Reverse Order ---" << endl;
    DNode* temp = dTail;
    int i = 1;
    while (temp != NULL) {
        cout << i << ". " << temp->song << endl;
        temp = temp->prev;
        i++;
    }
}
 
void freeAll() {
    while (sHead != NULL) {
        SNode* temp = sHead;
        sHead = sHead->next;
        delete temp;
    }
    while (dHead != NULL) {
        DNode* temp = dHead;
        dHead = dHead->next;
        delete temp;
    }
    dTail = NULL;
    current = NULL;
}
 
int main() {
    int choice;
    string song;
 
    while (true) {
        cout << "\n1.Add  2.Delete  3.Search  4.Show Playlist" << endl;
        cout << "5.Next  6.Previous  7.Now Playing  8.Show Reverse  0.Exit" << endl;
        cout << "Choice: ";
        cin >> choice;
 
        if (choice == 1) { cout << "Song: "; cin >> song; addSong(song); }
        else if (choice == 2) { cout << "Song: "; cin >> song; deleteSong(song); }
        else if (choice == 3) { cout << "Song: "; cin >> song; searchSong(song); }
        else if (choice == 4) { displayPlaylist(); }
        else if (choice == 5) { nextSong(); }
        else if (choice == 6) { prevSong(); }
        else if (choice == 7) { nowPlaying(); }
        else if (choice == 8) { displayReverse(); }
        else if (choice == 0) { freeAll(); cout << "Bye!" << endl; break; }
        else { cout << "Invalid choice." << endl; }
    }
    return 0;
}
 
