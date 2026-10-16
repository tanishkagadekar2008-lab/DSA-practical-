#include <iostream>
#include <string>
using namespace std;

/* 1. SINGLY LINKED LIST: Main Playlist */
struct Node {
    string song;
    Node* next;
};

Node* head = NULL;

void addSong(string song) {
    Node* newNode = new Node();
    newNode->song = song;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    cout << "Added: " << song << endl;
}

void showPlaylist() {
    cout << "\n--- Playlist ---" << endl;
    Node* temp = head;

    if (temp == NULL) {
        cout << "Playlist is empty." << endl;
        return;
    }

    while (temp != NULL) {
        cout << "- " << temp->song << endl;
        temp = temp->next;
    }
}

/* 2. STACK: Recently Played */
struct StackNode {
    string song;
    StackNode* next;
};

StackNode* top = NULL;

void push(string song) {
    StackNode* n = new StackNode();
    n->song = song;
    n->next = top;
    top = n;

    cout << "Playing: " << song << endl;
}

void pop() {
    if (top == NULL) {
        cout << "No history." << endl;
        return;
    }

    cout << "Going back from: " << top->song << endl;
    StackNode* temp = top;
    top = top->next;
    delete temp;
}

/* 3. QUEUE: Up Next */
struct QNode {
    string song;
    QNode* next;
};

QNode* front = NULL;
QNode* rear = NULL;

void enqueue(string song) {
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

void dequeue() {
    if (front == NULL) {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << "Playing from queue: " << front->song << endl;

    QNode* temp = front;
    front = front->next;
    delete temp;

    if (front == NULL)
        rear = NULL;
}

/* 4. DOUBLY LINKED LIST: Navigation */
struct DNode {
    string song;
    DNode* prev;
    DNode* next;
};

DNode* dHead = NULL;
DNode* current = NULL;

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
        n->prev = temp;
    }

    cout << "Added for navigation: " << song << endl;
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

/* 5. CIRCULAR LINKED LIST: Repeat Playlist */
struct CNode {
    string song;
    CNode* next;
};

CNode* last = NULL;

void addSongC(string song) {
    CNode* n = new CNode();
    n->song = song;

    if (last == NULL) {
        last = n;
        last->next = last;
    } else {
        n->next = last->next;
        last->next = n;
        last = n;
    }

    cout << "Added for repeat: " << song << endl;
}

void playRepeat(int count) {
    if (last == NULL) {
        cout << "Playlist empty." << endl;
        return;
    }

    if (count <= 0) {
        cout << "Enter a positive number." << endl;
        return;
    }

    CNode* temp = last->next;

    cout << "\n--- Repeat Play (" << count
         << " songs) ---" << endl;

    for (int i = 0; i < count; i++) {
        cout << "Playing: " << temp->song << endl;
        temp = temp->next;
    }
}

/* Free allocated memory */
void cleanup() {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    while (top != NULL) {
        StackNode* temp = top;
        top = top->next;
        delete temp;
    }

    while (front != NULL) {
        QNode* temp = front;
        front = front->next;
        delete temp;
    }
    rear = NULL;

    while (dHead != NULL) {
        DNode* temp = dHead;
        dHead = dHead->next;
        delete temp;
    }
    current = NULL;

    if (last != NULL) {
        CNode* first = last->next;
        last->next = NULL;

        while (first != NULL) {
            CNode* temp = first;
            first = first->next;
            delete temp;
        }

        last = NULL;
    }
}

/* MAIN MENU */
int main() {
    int choice, n;
    string song;

    while (true) {
        cout << "\n1. Add Song"
             << "\n2. Show Playlist"
             << "\n3. Play (Push)"
             << "\n4. Go Back (Pop)"
             << "\n5. Add to Queue"
             << "\n6. Play Next (Dequeue)"
             << "\n7. Add for Navigation"
             << "\n8. Next Song"
             << "\n9. Previous Song"
             << "\n10. Add for Repeat"
             << "\n11. Play Repeat"
             << "\n0. Exit"
             << "\nChoice: ";

        cin >> choice;

        if (choice == 1) {
            cout << "Song: ";
            cin >> song;
            addSong(song);
        } else if (choice == 2) {
            showPlaylist();
        } else if (choice == 3) {
            cout << "Song: ";
            cin >> song;
            push(song);
        } else if (choice == 4) {
            pop();
        } else if (choice == 5) {
            cout << "Song: ";
            cin >> song;
            enqueue(song);
        } else if (choice == 6) {
            dequeue();
        } else if (choice == 7) {
            cout << "Song: ";
            cin >> song;
            addSongD(song);
        } else if (choice == 8) {
            nextSong();
        } else if (choice == 9) {
            prevSong();
        } else if (choice == 10) {
            cout << "Song: ";
            cin >> song;
            addSongC(song);
        } else if (choice == 11) {
            cout << "How many: ";
            cin >> n;
            playRepeat(n);
        } else if (choice == 0) {
            cleanup();
            cout << "Bye!" << endl;
            break;
        } else {
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}
