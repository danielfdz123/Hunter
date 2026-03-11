// Daniel Andres Fernandez
// daniel.fernandez16@myhunter.cuny.edu
// December 5, 2022
// Lab 11C

#include <iostream>
using namespace std;

class Profile
{
private:
    string username;
    string displayname;

public:
    Profile(string usrn, string dspn); // Profile constructor for a user (initializing private variables username=usrn, displayname=dspn)
    Profile();                         // Default Profile constructor (username="", displayname="")
    string getUsername();              // Return username
    string getFullName();              // Return name in the format: "displayname (@username)"
    void setDisplayName(string dspn);  // Change display name
};

class Network
{
private:
    static const int MAX_USERS = 20; // max number of user profiles
    int numUsers;                    // number of registered users
    Profile profiles[MAX_USERS];     // user profiles array:
                                     // mapping integer ID -> Profile

    // Returns user ID (index in the 'profiles' array) by their username
    // (or -1 if username is not found)
    bool following[MAX_USERS][MAX_USERS]; // friendship matrix:
    // following[id1][id2] == true when id1 is following id2
    int findID(string usrn);

public:
    // Constructor, makes an empty network (numUsers = 0)
    Network();
    // Attempts to sign up a new user with specified username and displayname
    // return true if the operation was successful, otherwise return false
    bool addUser(string usrn, string dspn);
    // Make 'usrn1' follow 'usrn2' (if both usernames are in the network).
    // return true if success (if both usernames exist), otherwise return false
    bool follow(string usrn1, string usrn2); // new

    // Print Dot file (graphical representation of the network)
    void printDot(); // new
};

Profile::Profile(string usrn, string dspn)
{
    username = usrn;
    displayname = dspn;
}

Profile::Profile()
{
    username = "";
    displayname = "";
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
    for (int i = 0; i <= numUsers; i++)
    {
        if (profiles[i].getUsername() == usrn)
        {
            return i;
        }
    }

    return id;
}

Network::Network()
{
    numUsers = 0;
}

bool Network::addUser(string usrn, string dspn)
{
    if (numUsers < MAX_USERS && findID(usrn) == -1)
    {
        for (int j = 0; j < usrn.length(); j++)
        {
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
    if (findID(usrn1) != -1 && findID(usrn2) != -1)
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

    for (int i = 0; i < numUsers; i++)
    {
        cout << " " << "\"@" << profiles[i].getUsername() << "\"" << endl;
    }
    for (int i = 0; i < numUsers; i++)
    {
        for (int j = 0; j < numUsers; j++)
        {
            if (following[i][j] == true)
            {
                cout << " " << "\"@" << profiles[i].getUsername() << "\" -> \"@"
                     << profiles[j].getUsername() << "\"" << endl;
            }
        }
    }
    cout << "}" << endl;
}

int main()
{
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw.addUser("wario", "Wario");

    // add clone users who follow @mario
    for (int i = 2; i < 6; i++)
    {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi");

    nw.printDot();
}
