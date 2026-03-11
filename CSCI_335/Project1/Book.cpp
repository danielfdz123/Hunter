#include "Book.hpp"

//Write and document all methods in this file.

//Gives all elements of Book its default values
    Book::Book()
    {
        title_ = "NONE";
        author_ = "NONE";
        ISBN_ = 0;
        icon_ = nullptr;
        price_ = 0.00;
        keywords_ = {};
        blurb_ = "NONE";
    }

//Destructor, which deletes constructor info
    Book::~Book()
    {
        if(icon_ != nullptr)
        {
            delete[] icon_;
            icon_ = nullptr;
        } 
    }

//Copy constructor
    Book::Book(const Book& rhs)
    {
        title_ = rhs.title_;
        author_ = rhs.author_;
        ISBN_ = rhs.ISBN_;
        price_ = rhs.price_;
        keywords_ = rhs.keywords_;
        blurb_ = rhs.blurb_;

        if (rhs.icon_)
        {
            icon_ = new int[80]; // Allocate memory
            for (int i = 0; i < 80; i++)
            {
                icon_[i] = rhs.icon_[i];
            }
        }
        else
        {
            icon_ = nullptr;
        }
    }

//Copy Assignment
    Book& Book::operator=(const Book& rhs) //single & = l value
    {
        if(this != &rhs)
        {
            title_ = rhs.title_;
            author_ = rhs.author_;
            ISBN_ = rhs.ISBN_;
            if (rhs.icon_)
            {
                icon_ = new int[80]; // Allocate new memory
                for (int i = 0; i < 80; i++)
                {
                    icon_[i] = rhs.icon_[i];
                }
            }
            else
            {
                icon_ = nullptr;
            }
        }
        price_ = rhs.price_;
        keywords_ = rhs.keywords_;
        blurb_ = rhs.blurb_;
        return *this;
    }
        
//MOVE constructor :(
    Book::Book(Book&& rhs)
    {
        title_ = (std::move(rhs.title_));
        author_ = (std::move(rhs.author_));
        ISBN_ = rhs.ISBN_;
        icon_ = rhs.icon_;
        price_ = rhs.price_;
        keywords_ = (std::move(rhs.keywords_));
        blurb_ = (std::move(rhs.blurb_));
        rhs.icon_ = nullptr;
    //This resets any number value back to 0 or nullptr from the old objects
     
        // rhs.ISBN_ = 0;
        // rhs.price_ = 0.00; 
    }

//Move Assignment
    Book& Book::operator=(Book&& rhs) //double & = means r value
    {
        if (this != &rhs) 
        {
            title_ = std::move(rhs.title_);
            author_ = std::move(rhs.author_);
            ISBN_ = rhs.ISBN_;
            icon_ = rhs.icon_;
            price_ = rhs.price_;
            keywords_ = std::move(rhs.keywords_);
            blurb_ = std::move(rhs.blurb_);
    
    //This resets any number value back to 0 or nullptr from the old objects
            rhs.icon_ = nullptr;
            rhs.ISBN_ = 0;
            rhs.price_ = 0.00;
        }
    return *this;
    }

    const std::string& Book::getTitle() const
    {
        return title_;
    }

    void Book::setTitle(const std::string& title)
    {
        title_ = title;
    }

    const std::string& Book::getAuthor() const
    {
        return author_;
    }

    void Book::setAuthor(const std::string& author)
    {
        author_ = author;
    }

    long long int Book::getISBN() const
    {
        return ISBN_;
    }

    void Book::setISBN(long long int ISBN)
    {
        ISBN_ = ISBN;
    }

    const int* Book::getIcon() const
    {
        return icon_;
    }

    void Book::setIcon(int* icon)
    {
        icon_ = icon;
    }

    float Book::getPrice() const
    {
        return price_;
    }

    void Book::setPrice(float price)
    {
        price_ = price;
    }

    const std::vector<std::string>& Book::getKeywords() const
    {
        return keywords_;
    }

    void Book::setKeywords(const std::vector<std::string>& keywords)
    {
        keywords_ = keywords;
    }

    const std::string& Book::getBlurb() const
    {
        return blurb_;
    }

    void Book::setBlurb(const std::string& blurb)
    {
        blurb_ = blurb;
    }

    void Book::print() const
    {
        std::cout << "Title: " << getTitle() << "\n";
        std::cout << "Author: " << getAuthor() << "\n";
        std::cout << "ISBN: " << getISBN() << "\n";
        std::cout << "Icon: " ; //<< getIcon() << "\n";

    //Loops through the array to print out the integers
        for(int i = 0; i < 80; i++)
        {
            std::cout<< icon_[i] << " ";
        }
        std::cout << std::endl;
        
    //Normal print for Price and makes sure that it prints out 2 digits after the decimal place
        std::cout << "Price: " << "$" << std::fixed << std::setprecision(2) << getPrice() << std::endl;
    //Loops through the vector to print out each keyword one by one, split by a comma
        std::cout << "Keywords: ";
       
        for (int i = 0; i < getKeywords().size(); i++) 
        {
            if (i != getKeywords().size() - 1) 
            {
                std::cout<<getKeywords()[i] << ", ";
            }
            else 
            {
                std::cout<<getKeywords()[i] << "\n";
            }
        }

        
        std::cout << "Blurb: " << getBlurb() << "\n\n";
    }