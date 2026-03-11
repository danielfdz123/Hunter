// Daniel Andres Fernandez
// danitl.fernandez16@myhunter.cuny.edu
// October 28, 2022
// Lab 10d

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

enum Genre
{
    ACTION,
    COMEDY,
    DRAMA,
    ROMANCE,
    THRILLER
};

class Time
{
public:
    int h;
    int m;
};

class Movie
{
public:
    string title;
    Genre genre;  // only one genre per movie
    int duration; // in minutes
};

class TimeSlot
{
public:
    Movie movie;    // what movie
    Time startTime; // when it starts
};

int minutesSinceMidnight(Time time)
{
    int final = 0;
    final += time.m;
    final += time.h * 60;
    return final;
}

int minutesUntil(Time earlier, Time later)
{
    int total = 0;
    total += later.m - earlier.m;
    total += (later.h - earlier.h) * 60;
    return total;
}

Time addMinutes(Time time, int min)
{
    Time newTime;
    newTime.h = time.h + (time.m + min) / 60;
    newTime.m = (time.m + min) % 60;
    return newTime;
}

void printMovie(Movie mv)
{
    string g;
    switch (mv.genre)
    {
    case ACTION:
        g = "ACTION";
        break;
    case COMEDY:
        g = "COMEDY";
        break;
    case DRAMA:
        g = "DRAMA";
        break;
    case ROMANCE:
        g = "ROMANCE";
        break;
    case THRILLER:
        g = "THRILLER";
        break;
    }
    cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

void printTimeSlot(TimeSlot ts)
{
    Time endingTime = addMinutes(ts.startTime, ts.movie.duration);
    printMovie(ts.movie);
    cout << " [starts at " << ts.startTime.h << ":" << ts.startTime.m << ", ends by " << endingTime.h << ":" << endingTime.m << "]" << "\n";
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie)
{
    Time newStartTime = addMinutes(ts.startTime, ts.movie.duration);
    return {nextMovie, newStartTime};
}

int main()
{
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    Movie movie2 = {"Black Panther", THRILLER, 134};
    TimeSlot daytime = {movie2, {12, 15}};
    TimeSlot daytime2 = {movie1, {14, 25}};
    cout << "First movie: ";
    printTimeSlot(daytime);
    TimeSlot afterFirstMovie = scheduleAfter(daytime, movie1);
    cout << "Second movie: ";
    printTimeSlot(afterFirstMovie);
}