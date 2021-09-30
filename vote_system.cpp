//including necessary library
#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<sstream>
using namespace std;
//class of movies information
class movie
{
   private :
       string titleID;
       int ordering;
       string title;
       string region;
       string language;
       string types;
       string attributes;
       bool isOrginalTitle;
   public :
       // setter function
       void set_titleID(string TI){ titleID = TI; }
       void set_ordring(int order){ ordering = order; }
       void set_title(string subject){ title = subject; }
       void set_region(string place){ region = place; }
       void set_language(string lan){ language = lan; }
       void set_types(string arr){ types = arr;

           /*
                      int j=0;
           for(auto i : arr){
            types[j]=i;
            j++;
           }
           ////////////////////////
             do{
                types[j]=arr[j];
                 j++;
             }while(arr[j]!=nullptr);
           */
       }
       void set_attributes(string att){ attributes = att;
           /*
                      int j=0;
           for(auto i : att){
            attributes[j]=i;
            j++;
           }
           //////////////////////////
             do{
                 attributes[j]=att[j];
                 j++;
             }while(att[j]!=nullptr);
           */
       }
       void set_isOrigin(bool makeSure){ isOrginalTitle = makeSure; }
       //getter function
       string get_titleID(){ return titleID; }
       int get_ordring(){ return ordering; }
       string get_title(){ return title; }
       string get_region(){ return region; }
       string get_types(){
         /*  for(auto i : types){
            return i;
           } */
           return types;
       }
       string get_attributes(){
          /* for(auto i : attributes){
            return i;
           } */
           return attributes;
       }
       bool get_isOrigin(){ return isOrginalTitle;}


};
class voteRate
{
   private :
      string tconst;
      float averageRating;
      int numVotes;
   public :
       //setter function
       void set_tconst(string id){ tconst = id; }
       void set_averageRating(float average){ averageRating = average; }
       void set_numVote(int num){ numVotes = num; }
       //getter function
       string get_tconst(){ return tconst; }
       float get_averageRating(){ return averageRating; }
       int get_numVote(){ return numVotes; }
};
using namespace std;
int main()
{
     movie obj[45];
     voteRate Rate[45];
     string TI , sub , place , lan , kind , att , tconst ;
     int order , counter=0 , numVote;
     float averageRating;
     bool makeSure;
     ifstream file_movie;
     file_movie.open("title.akas.txt");
     if(!file_movie){
        cout<<"error when opening file\n";
        exit(1);
     }

     string line;
     string ord , isOrginal;
     while (getline(file_movie, line))
    {

    std::stringstream  linestream(line);
    getline(linestream, TI, '\t');
    getline(linestream ,ord, '\t');
    getline(linestream, sub, '\t');
    getline(linestream, place, '\t');
    getline(linestream, lan, '\t');
    getline(linestream, kind, '\t');
    getline(linestream, att , '\t');
    getline(linestream, isOrginal, '\t');
    //setting data to class object
      if(counter!=0){
         obj[counter].set_titleID(TI);
         //converting string to integer
         stringstream ss;
         ss << ord;
         ss >> order;
         obj[counter].set_ordring(order);
         obj[counter].set_title(sub);
         obj[counter].set_region(place);
         obj[counter].set_language(lan);
         obj[counter].set_types(kind);
         obj[counter].set_attributes(att);
         //converting string to boolean
          if(isOrginal=="1")
            makeSure = true;
          else
            makeSure = false;
         obj[counter].set_isOrigin(makeSure);
       }


    //cout<<counter<<endl;
   //  cout<<obj[counter].get_titleID()<<"\t"<<ord<<"\t"<<sub<<"\t"<<place<<"\t"<<lan<<"\t"<<kind<<"\t"<<att<<"\t"<<isOrginal<<endl;
      counter++;
    }
     file_movie.close();
    // opening rating file
    ifstream file_rating;
    file_rating.open("title.ratings.txt");
    if(!file_rating){
        cout<<"error when opening file\n";
        exit(1);
     }
     string num , average;
     int c=0;
     while (getline(file_rating, line)){
          std::stringstream  linestream(line);
          getline(linestream, tconst , '\t');
          getline(linestream ,average , '\t');
          getline(linestream, num, '\t');
            if(c!=0){
             Rate[c].set_tconst(tconst);
             //converting string to float
             averageRating = atof(average.c_str());
             Rate[c].set_averageRating(averageRating);
             //converting string to int
             stringstream str;
             str << num;
             str >> numVote;
             Rate[c].set_numVote(numVote);
           //  cout<<Rate[c].get_tconst()<<"\t"<<Rate[c].get_averageRating()<<"\t"<<Rate[c].get_numVote()<<endl;
            }

            c++;
     }

     return 0;
}










