/*
 * SIMPLE VERSION - Music Playlist Manager
 * Unit 3 - Linked List
 *
 * Uses plain functions (no classes) so it's easy to read and explain.
 * Each of the 5 linked list types has its own small part below.
 *
 * Compile: g++ playlist_simple.cpp -o playlist_simple
 * Run    : ./playlist_simple
 */

#include <iostream>
#include <string>
using namespace std;

/* ---------- 1. SINGLY LINKED LIST : main playlist ---------- */
struct Node {
    string song;
    Node* next;
};
Node* head = NULL;   // start of the playlist

void addSong(string song) {
    Node* newNode = new Node();
    newNode->song = song;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;          // first song
    } else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;   // go to last node
        temp->next = newNode;    // attach new node
    }
    cout << "Added: " << song << endl;
}

void showPlaylist() {
    cout << "\n--- Playlist ---" << endl;
    Node* temp = head;
    while (temp != NULL) {
        cout << "- " << temp->song << endl;
        temp = temp->next;
    }
}

/* ---------- 2. STACK (using linked list) : recently played ---------- */
struct StackNode {
    string song;
    StackNode* next;
};
StackNode* top = NULL;

void push(string song) {           // play a song -> add to top
    StackNode* n = new StackNode();
    n->song = song;
    n->next = top;
    top = n;
    cout << "Playing: " << song << endl;
}

void pop() {                        // go back -> remove top
    if (top == NULL) {
        cout << "No history." << endl;
        return;
    }
    cout << "Going back from: " << top->song << endl;
    StackNode* temp = top;
    top = top->next;
    delete temp;
}

/* ---------- 3. QUEUE (using linked list) : up next ---------- */
struct QNode {
    string song;
    QNode* next;
};
QNode* front = NULL;
QNode* rear = NULL;

void enqueue(string song) {         // add song to the end of the queue
    QNode* n = new QNode();
    n->song = song;
    n->next = NULL;
    if (front == NULL) {
        front = rear = n;
    } else {
        rear->next = n;
        rear = n;
    }
    cout << "Added to queue: " << song << endl;
}

void dequeue() {                    // play the song at the front
    if (front == NULL) {
        cout << "Queue is empty." << endl;
        return;
    }
    cout << "Playing from queue: " << front->song << endl;
    QNode* temp = front;
    front = front->next;
    delete temp;
}

/* ---------- 4. DOUBLY LINKED LIST : next / previous song ---------- */
struct DNode {
    string song;
    DNode* prev;
    DNode* next;
};
DNode* dHead = NULL;
DNode* current = NULL;   // currently playing song

void addSongD(string song) {
    DNode* n = new DNode();
    n->song = song;
    n->prev = NULL;
    n->next = NULL;

    if (dHead == NULL) {
        dHead = current = n;
    } else {
        DNode* temp = dHead;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = n;
        n->prev = temp;        // link back - this is what makes it "doubly" linked
    }
}

void nextSong() {
    if (current != NULL && current->next != NULL) {
        current = current->next;
        cout << "Now playing: " << current->song << endl;
    } else {
        cout << "No next song." << endl;
    }
}

void prevSong() {
    if (current != NULL && current->prev != NULL) {
        current = current->prev;
        cout << "Now playing: " << current->song << endl;
    } else {
        cout << "No previous song." << endl;
    }
}

/* ---------- 5. CIRCULAR LINKED LIST : repeat-all mode ---------- */
struct CNode {
    string song;
    CNode* next;
};
CNode* last = NULL;   // last node; last->next always points back to the first node

void addSongC(string song) {
    CNode* n = new CNode();
    n->song = song;

    if (last == NULL) {
        last = n;
        last->next = last;         // points to itself (circle of one)
    } else {
        n->next = last->next;      // new node points to the first node
        last->next = n;            // old last points to new node
        last = n;                  // new node becomes the last node
    }
}

void playRepeat(int count) {
    if (last == NULL) {
        cout << "Playlist empty." << endl;
        return;
    }
    CNode* temp = last->next;      // start from the first song
    cout << "\n--- Repeat Play (" << count << " songs) ---" << endl;
    for (int i = 0; i < count; i++) {
        cout << "Playing: " << temp->song << endl;
        temp = temp->next;         // loops back automatically, never hits NULL
    }
}

/* ---------- MAIN MENU ---------- */
int main() {
    int choice;
    string song;
    int n;

    while (true) {
        cout << "\n1.Add Song   2.Show Playlist" << endl;
        cout << "3.Play (push)   4.Go Back (pop)" << endl;
        cout << "5.Add to Queue   6.Play Next (dequeue)" << endl;
        cout << "7.Add for Nav   8.Next   9.Previous" << endl;
        cout << "10.Add for Repeat   11.Play Repeat" << endl;
        cout << "0.Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) { cout << "Song: "; cin >> song; addSong(song); }
        else if (choice == 2) { showPlaylist(); }
        else if (choice == 3) { cout << "Song: "; cin >> song; push(song); }
        else if (choice == 4) { pop(); }
        else if (choice == 5) { cout << "Song: "; cin >> song; enqueue(song); }
        else if (choice == 6) { dequeue(); }
        else if (choice == 7) { cout << "Song: "; cin >> song; addSongD(song); }
        else if (choice == 8) { nextSong(); }
        else if (choice == 9) { prevSong(); }
        else if (choice == 10) { cout << "Song: "; cin >> song; addSongC(song); }
        else if (choice == 11) { cout << "How many: "; cin >> n; playRepeat(n); }
        else if (choice == 0) { cout << "Bye!" << endl; break; }
        else { cout << "Invalid choice." << endl; }
    }
    return 0;
}