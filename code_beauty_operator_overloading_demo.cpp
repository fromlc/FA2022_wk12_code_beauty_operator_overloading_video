//------------------------------------------------------------------------------
// code_beauty_operator_overloading_demo.cpp
// 
// Author: Code Beauty on YouTube: https://youtu.be/BnMnozsSPmw
//------------------------------------------------------------------------------
#include <iostream>
#include<string>
#include<list>

using namespace std;

//------------------------------------------------------------------------------
// YouTubeChannel
//
// struct used because all members are public by default
//------------------------------------------------------------------------------
struct YouTubeChannel {
    string Name;
    int SubscribersCount;

    // constructor
    YouTubeChannel(string name, int subscribersCount) {
        Name = name;
        SubscribersCount = subscribersCount;
    }

    // overload equal to comparison operator ==
    bool operator==(const YouTubeChannel&channel) const{
        return this->Name == channel.Name;
    }
};

//------------------------------------------------------------------------------
// overload insertion operator << to display a YouTubeChannel instance
// 
// global function
//------------------------------------------------------------------------------
ostream& operator<<(ostream& COUT, YouTubeChannel& ytChannel) {
    COUT << "Name: " << ytChannel.Name << endl;
    COUT << "Subscribers: " << ytChannel.SubscribersCount << endl;
    return COUT;
}

//------------------------------------------------------------------------------
// MyCollection
// 
// contains a list of YouTubeChannel class instances
//
// struct used because all members are public by default
//------------------------------------------------------------------------------
struct MyCollection {
    list<YouTubeChannel>myChannels;

    // overload math operator +=
    void operator+=(YouTubeChannel& channel) {
        this->myChannels.push_back(channel);
    }

    // overload math operator -=
    void operator-=(YouTubeChannel& channel) {
        this->myChannels.remove(channel);
    }
};

//------------------------------------------------------------------------------
// overload insertion operator << to display all items in MyCollection
// 
// global function
//------------------------------------------------------------------------------
ostream& operator<<(ostream& COUT, MyCollection& myCollection) {

    for (YouTubeChannel ytChannel : myCollection.myChannels)
        COUT << ytChannel << endl;

    return COUT;
}

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

    YouTubeChannel yt1 = YouTubeChannel("CodeBeauty", 75000);
    YouTubeChannel yt2 = YouTubeChannel("My second channel", 80000);

    MyCollection myCollection;
    myCollection += yt1;
    myCollection += yt2;
    myCollection -= yt2;

    cout << myCollection;
    
    cin.get();
}