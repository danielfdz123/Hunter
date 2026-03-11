//Daniel Andres Fernandez
//daniel.fernandez16@myhunter.cuny.edu
//December 5, 2022
//Lab 11D

#include <iostream>
#include <string>
using namespace std;

struct Post
{
    string username;
    string message;
};

class Profile
{
private:
    string username;
    string displayname;
public:
    Profile(string usrn, string dspn);      // Profile constructor for a user (initializing private variables username=usrn, displayname=dspn)
    Profile();                              // Default Profile constructor (username="", displayname="")
    string getUsername();                   // Return username
    string getFullName();                   // Return name in the format: "displayname (@username)"
    void setDisplayName(string dspn);       // Change display name
};


class Network 
{
private:
    static const int MAX_USERS = 20;        // max number of user profiles
    int numUsers;                           // number of registered users
    Profile profiles[MAX_USERS];            // user profiles array:
                                            // mapping integer ID -> Profile
    static const int MAX_POSTS = 100;
    int numPosts;                           // number of posts
    Post posts[MAX_POSTS];                  // array of all posts

    // Returns user ID (index in the 'profiles' array) by their username (or -1 if username is not found)
    bool following[MAX_USERS][MAX_USERS];   // friendship matrix: following[id1][id2] == true when id1 is following id2
    int findID(string usrn);
public:
    Network();                                  // Constructor, makes an empty network (numUsers = 0)
    bool addUser(string usrn, string dspn);     
    // Make 'usrn1' follow 'usrn2' (if both usernames are in the network).
    // return true if success (if both usernames exist), otherwise return false
    bool follow(string usrn1, string usrn2); // new

    // Print Dot file (graphical representation of the network)
    void printDot();                         // new

    // Add a new post
    bool writePost(string usrn, string msg);
    // Print user's "timeline"
    bool printTimeline(string usrn);
};
    
Profile::Profile(string usrn, string dspn)
{
    username = usrn;
    displayname = dspn;
}

Profile::Profile()
{
    username="";
    displayname="";
}

string Profile::getUsername()
{
    return username;
}

string Profile::getFullName()
{
    string name = " (@" + username + ")";
    string n = displayname + name;
    return n;
}

void Profile::setDisplayName(string dspn)
{
    displayname = dspn;
}

int Network::findID(string usrn) 
{
    int id = -1;

    for(int i = 0; i <= numUsers; i++) 
    {
        if(profiles[i].getUsername() == usrn) 
        {
            return i;
        }
    }
    return id;
}

Network::Network() 
{
    numUsers = 0;
    numPosts = 0;
    for(int max1 = 0; max1 < MAX_USERS; max1++) 
    {
        for(int max2 = 0; max2 < MAX_USERS; max2++) 
        {
            following[max1][max2] = false;
        }
    }
}

bool Network::addUser(string usrn, string dspn) \
{
    if(numUsers < MAX_USERS && findID(usrn) == -1) 
    {
        for(int j = 0;j < usrn.length();j++){
            if (!isdigit(usrn[j]) && !isalpha(usrn[j])) 
            {
                return false;
            }
        }
        Profile adding(usrn, dspn);
        profiles[numUsers] = adding;
        numUsers++;
        return true;
    } 
    else 
    {
        return false;
    }
}

bool Network::follow(string usrn1, string usrn2) 
{
    if(findID(usrn1) != -1 && findID(usrn2) != -1) 
    {
        following[findID(usrn1)][findID(usrn2)] = true;
        return true;
    } 
    else 
    {
        return false;
    }
}

void Network::printDot() 
{
    cout << "digraph {" << endl;

    for(int i = 0; i < numUsers; i++) 
    {
        cout << " " << "\"@" << profiles[i].getUsername() << "\"" << endl;
    }
    for(int i = 0; i < numUsers; i++) 
    {
        for(int j = 0; j < numUsers; j++) 
        {
            if(following[i][j] == true) 
            {
                cout << " " << "\"@" << profiles[i].getUsername() << "\" -> \"@" << profiles[j].getUsername() << "\"" << endl;
            }
        }
    }
    cout << "}" << endl;
}

bool Network::writePost(string usrn, string msg) 
{
    int index = findID(usrn);

    if(index == -1 || numPosts == MAX_POSTS) 
    {
        return false;
    }
    posts[numPosts].username = usrn;
    posts[numPosts].message = msg;
    numPosts++;
    return true;
}

bool Network::printTimeline(string usrn) 
{
    int userIndex = findID(usrn);

    if(userIndex == -1) 
    {
        return false;
    }
    for(int i = numPosts - 1; i >= 0; i--) 
    {
        Post p = posts[i];
        int writeIndex = findID(p.username);

        if(p.username == usrn) 
        {
            cout << profiles[userIndex].getFullName() << ": " << p.message << endl;
        } 
        else if(following[userIndex][writeIndex]) 
        {
            cout << profiles[writeIndex].getFullName() << ": " << p.message << endl;
        }
    }
    return true;
}

int main() 
{
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");
    
    nw.follow("mario", "luigi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");

    // write some posts
    nw.writePost("mario", "It's a-me, Mario!");
    nw.writePost("luigi", "Hey hey!");
    nw.writePost("mario", "Hi Luigi!");
    nw.writePost("yoshi", "Test 1");
    nw.writePost("yoshi", "Test 2");
    nw.writePost("luigi", "I just hope this crazy plan of yours works!");
    nw.writePost("mario", "My crazy plans always work!");
    nw.writePost("yoshi", "Test 3");
    nw.writePost("yoshi", "Test 4");
    nw.writePost("yoshi", "Test 5");

    cout << endl;
    cout << "======= Mario's timeline =======" << endl;
    nw.printTimeline("mario");
    cout << endl;

    cout << "======= Yoshi's timeline =======" << endl;
    nw.printTimeline("yoshi");
    cout << endl;
}
