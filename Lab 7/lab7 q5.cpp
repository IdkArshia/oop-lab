#include<iostream>
#include<string>
using namespace std;

class Media {
protected:
    string title;
    string publicationDate;
    int uniqueID;
    string publisher;
    bool isCheckedOut = false;
public:
    Media(string t, string pubDate, int id, string pub): title(t), publicationDate(pubDate), uniqueID(id), publisher(pub) {}

    virtual void displayInfo() {
        cout<<"Title:"<<title<<endl;
        cout<<"Publication Date:"<<publicationDate<<endl;
        cout<<"ID:"<<uniqueID<<endl;
        cout<<"Publisher:"<<publisher<<endl;
        cout<<"Status:"<<(isCheckedOut? "Checked Out" : "Available")<<endl;
    }
    void checkOut() {
        if (!isCheckedOut) {
            isCheckedOut = true;
            cout<<"Item checked out successfully."<<endl;
        } else {
            cout<<"Item is already checked out."<<endl;
        }
    }
    void returnItem() {
        if (isCheckedOut) {
            isCheckedOut = false;
            cout<<"Item returned successfully."<<endl;
        } else {
            cout<<"Item was not checked out."<<endl;
        }
    }
    string getTitle(){ return title; }
    string getPublicationDate(){ return publicationDate; }
    int getID(){ return uniqueID; }
};

class Book:public Media {
    string author;
    string ISBN;
    int numberOfPages;
public:
    Book(string t, string pubDate, int id, string pub, string auth, string isbn, int pages):Media(t, pubDate, id, pub),author(auth),ISBN(isbn),numberOfPages(pages) {}

    void displayInfo() override {
        Media::displayInfo();
        cout<<"Author:"<<author<<endl;
        cout<<"ISBN:"<<ISBN<<endl;
        cout<<"Pages:"<<numberOfPages<<endl;
    }

    string getAuthor()const{return author; }
};

class DVD:public Media {
    string director;
    string duration;
    string rating;

public:
    DVD(string t, string pubDate, int id, string pub, string dir, string dur, string rate):Media(t, pubDate, id, pub),director(dir),duration(dur),rating(rate){};

    void displayInfo() override {
        Media::displayInfo();
        cout<<"Director:"<<director<<endl;
        cout<<"Duration:"<<duration<<endl;
        cout<<"Rating:"<<rating<<endl;
    }

    string getDirector() const {return director; }
};

class CD: public Media {
    string artist;
    int numberOfTracks;
    string genre;

public:
    CD(string t, string pubDate, int id, string pub, string art, int tracks, string gen):Media(t, pubDate, id, pub),artist(art),numberOfTracks(tracks),genre(gen){}

    void displayInfo() override {
        Media::displayInfo();
        cout<<"Artist:"<<artist<<endl;
        cout<<"Tracks:"<<numberOfTracks<<endl;
        cout<<"Genre:"<<genre<<endl;
    }

    string getArtist()const{ return artist; }
};

void search(Media* media[], int size, string title) {
    cout<<"Searching by title: "<<title<<endl;
    for (int i = 0; i < size; i++) {
        if (media[i]->getTitle() == title) {
            media[i]->displayInfo();
        }
    }
}

void search(Book* books[], int size, string author) {
    cout<<"Searching books by author: "<<author<<endl;
    for (int i = 0; i < size; i++) {
        if (books[i]->getAuthor() == author) {
            books[i]->displayInfo();
        }
    }
}

void search(Media* media[], int size, int year) {
    cout<<"Searching by publication year: "<<year<<endl;
    for (int i = 0; i < size; i++) {
        string pubDate = media[i]->getPublicationDate();
        if (stoi(pubDate.substr(0, 4)) == year) {
            media[i]->displayInfo();
        }
    }
}

int main() {
    Book* b1 = new Book("C++ Fundamentals", "2022-03-15", 101, "Pearson", "Bjarne Stroustrup", "1234567890", 550);
    DVD* d1 = new DVD("Inception", "2010-07-16", 102, "Warner Bros", "Christopher Nolan", "2h28m", "PG-13");
    CD* c1 = new CD("Thriller", "1982-11-30", 103, "Epic", "Michael Jackson", 9, "Pop");
    Media* library[3] = {b1, d1, c1};
    Book* books[1] = {b1};
    b1->checkOut();
    b1->returnItem();
    search(library, 3, "Inception");
    search(books, 1, "Bjarne Stroustrup");
    search(library, 3, 1982);
    return 0;
}
