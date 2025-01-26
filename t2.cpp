#include <iostream>
#include <list>
using namespace std;

class YoutubeChannel{
private:
    string Name;
    int SubscribersCount;
    list<string> PublishedVideoTitles;
protected:
    string OwnerName;
    int ContentQuality;

public:
    YoutubeChannel(string name, string ownerName){
        Name = name;
        OwnerName = ownerName;
        SubscribersCount = 0;
        ContentQuality = 0;
    }

    void GetInfo(){
        cout << Name<< endl;
        cout << OwnerName << endl;
        cout << SubscribersCount << endl;
        cout << "Videos:"<< endl;
        for (string videoTitle: PublishedVideoTitles){
            cout << videoTitle << endl;
        }
    }

    void Subscribe(){
        SubscribersCount++;
    }
    void Unsubscribe(){
        if (SubscribersCount > 1){
            SubscribersCount--;
        }
    }
    void PublishVideo(string title){
        PublishedVideoTitles.push_back(title);
    }

    void CheckAnalytics(){
        if (ContentQuality < 5)
            cout << Name << " channel has a bad content"<< endl;
        else
            cout << Name << " channel has great contents!"<< endl; 
    }
};

class CookingYoutubeChannel: public YoutubeChannel{
public:
    CookingYoutubeChannel(string name, string ownerName): YoutubeChannel(name, ownerName){

    }

    void Practice(){
        cout << OwnerName << " practice, learning new things and practice again" << endl;
        ContentQuality++;
    }

};

class SingersYoutubeChannel: public YoutubeChannel{
public:
    SingersYoutubeChannel(string name, string ownerName) :YoutubeChannel(name, ownerName){

    }

    void Practice(){
        cout << OwnerName << " is learning how to sing, taking singing classes, and how to dance!" << endl;
        ContentQuality++;
    }

};

int main(){
    CookingYoutubeChannel cyc("lawal's channel", "Jibola");
    SingersYoutubeChannel syc("kabi sings", "kabirat");
    cyc.Practice();
    syc.Practice();
    syc.Practice();
    syc.Practice();
    syc.Practice();
    syc.Practice();
    syc.Practice();

    YoutubeChannel * yt1 = &cyc;
    YoutubeChannel * yt2 = &syc;

    yt1 ->CheckAnalytics();
    yt2 ->CheckAnalytics();
    cyc.CheckAnalytics();
    syc.CheckAnalytics();

    return 0;
}