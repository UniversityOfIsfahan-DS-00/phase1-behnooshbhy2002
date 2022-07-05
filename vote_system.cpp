//including necessary library
#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<sstream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
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
       void set_types(string arr){ types = arr;}
       void set_attributes(string att){ attributes = att;}
       void set_isOrigin(bool makeSure){ isOrginalTitle = makeSure; }

       //getter function
       string get_titleID(){ return titleID; }
       int get_ordring(){ return ordering; }
       string get_title(){ return title; }
       string get_region(){ return region; }
       string get_language(){ return language; }
       string get_types(){ return types; }
       string get_attributes(){ return attributes; }
       bool get_isOrigin(){ return isOrginalTitle; }


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
class user
{
    private :
        string username;
        string password;
        string list_movie_vote[45];
    public :
        int Num_movies=0;
        //int Num_person=0;
        void set_username(string users){ username = users; }
        void set_password(string pass){ password = pass; }
        void set_listOfMovie(string id)
        {
            Num_movies++;
            list_movie_vote[Num_movies] = id;
        }
        string get_username(){ return username; }
        string get_password(){ return password; }
        string *get_listOfMovie()
        {
            return list_movie_vote;
        }
        //checking input username
        bool check_user(string users , user person[] , int num)
        {
            for(int i=0; i<num; i++){
                if(users == person[i].get_username()){
                    return true;
                }
            }
            return false;
        }
        //checking input password
        bool check_pass(string users , string pass , user person[] , int num){
            for(int i=0; i<num; i++){
                if(users == person[i].get_username() ){
                     if(pass == person[i].get_password() )
                        return true;
                     else
                        return false;
                }
            }
        }
        //checking delicated votes
        bool check_vote( string id  ){
             int len = sizeof(list_movie_vote) / sizeof(list_movie_vote[0]);

             for(int i=0; i<len; i++){
                 if(list_movie_vote[i]==id)
                    return true;
             }
             return false;
        }

};
//chicking ides and returning name of movie
string findName(string id , movie obj[] , int num)
{
    for(int i=1; i<num; i++){
        if(obj[i].get_titleID()==id)
            return obj[i].get_title();
    }
}
//showing movies with information
void showTable(movie obj[] , voteRate rate[] , int num_movie)
{
    printf("%-10s | %-10s | %-15s | %-10s | %-10s | %-10s | %-10s | %-5s | %-5s | \n" ,"titleId" ,"ordering" , "title"  , "region" ,"Rating",
            "language" , "types" ,"attributes" , "isOriginalTitle" );
    cout<<"---------------------------------------------------------------------------------------------------------------------------\n\n";
        for(int i=1; i<num_movie; i++){

            printf("%-10s | %-10d | %-15s | %-10s | %-10.1f | " , obj[i].get_titleID().c_str()  ,
                                            obj[i].get_ordring() , obj[i].get_title().c_str() , obj[i].get_region().c_str() , floor( rate[i].get_averageRating() * 10 + .5 ) / 10 );
            printf( "%-10s | %-10s | %-5s | %-5d | \n\n" , obj[i].get_language().c_str() ,
                                            obj[i].get_types().c_str() , obj[i].get_attributes().c_str() ,obj[i].get_isOrigin());
            cout<<"---------------------------------------------------------------------------------------------------------------------------\n\n";
        }
}
//vote part
void vote_movie(user person[] , voteRate rate[] , int num_movie , int shomare){
    bool flag=true;
    string id;
    float rating;
    while(flag){
            cout<<"Enter title id of movie : ";
            cin>>id;
                if( person[shomare].check_vote( id ))
                    cout<<"\n--You have voted to this movie before please choose another one--\n\n";
                else{ 
                    for(int i=1; i<num_movie; i++){
                        if(id==rate[i].get_tconst()){
                             flag=false;
                             break;
                        }
                        
                    }
                    if(flag)
                    cout<<"\n--please enter another id--\n\n";
                }
                  
            }
            cout<<"Enter your rating : ";
                do{
                    cin>>rating;
                       if(rating < 0 || rating > 10)
                          cout<<"\n--Invalid rating try again--\n\nEnter your rating : ";
                }while(rating < 0 || rating > 10);

                for(int i=0; i<num_movie; i++){
                    if(rate[i].get_tconst()==id){
                        float r = ( ( rate[i].get_averageRating()*rate[i].get_numVote())+rating ) / (rate[i].get_numVote()+1);
                        r = floor ( r * 10 + .5 ) / 10;
                        rate[i].set_averageRating(r);
                        rate[i].set_numVote(rate[i].get_numVote() + 1);
                        cout<<"\nNew rating : "<<(rate[i].get_averageRating())<<endl<<"Number Of Votes : "<<(rate[i].get_numVote())<<endl<<endl;
                    }
                }
                   person[shomare].set_listOfMovie( id);
}
//sort and print TopTen Movies
void Sort(voteRate rate[] , movie obj[] , int num_movie)
{
     voteRate temp[45];
     string id;
     float av_rating;
     int num;
     //copy rating 
     for(int k=0; k<num_movie; k++){
        temp[k].set_tconst(rate[k].get_tconst());
        temp[k].set_averageRating(rate[k].get_averageRating());
        temp[k].set_numVote(rate[k].get_numVote());
     }
    //sort movies by rating
     for(int k=0; k<num_movie; k++){
        for(int j=k+1; j<num_movie; j++){
            if(temp[j].get_averageRating() > temp[k].get_averageRating()){

                id = temp[j].get_tconst();
                av_rating = temp[j].get_averageRating();
                num = temp[j].get_numVote();

                temp[j].set_tconst(temp[k].get_tconst());
                temp[j].set_averageRating(temp[k].get_averageRating());
                temp[j].set_numVote(temp[k].get_numVote());

                temp[k].set_tconst(id);
                temp[k].set_averageRating(av_rating);
                temp[k].set_numVote(num);

                }
          }
     }
     //printig TopTen
     printf(" %-50s | %-10.1s|\n" , "Title" , "Rating");
      cout<<"------------------------------------------------------------------\n";
    for(int k=0; k<10; k++){
        printf(" %-50s | %-10.1f |\n" , findName(temp[k].get_tconst() , obj , num_movie).c_str() , temp[k].get_averageRating());
       cout<<"------------------------------------------------------------------\n";
        }
}
//Menu
void menu(user person[] , movie obj[] , voteRate rate[] , int shomare , int num_movie)
{
    int choise;
    bool flag=true;

    while(flag==true){
        cout<<"1.Show movie's list\n";
        cout<<"2.vote movie\n";
        cout<<"3.Top Ten\n";
        cout<<"4.Exit\n";
        cin>>choise;
         switch(choise){
              case 1:
                 showTable( obj , rate , num_movie );
                 break;
              case 2:
                 vote_movie( person , rate , num_movie , shomare );
                 break;
              case 3:
                 Sort( rate , obj , num_movie );
                 break;
               case 4:
                 flag=false;
                 break;

         }
    }
}
//User
void UserPart(movie obj[] , voteRate Rate[] , int counter){


    cout<<"**   **  **** **    **    **  ****   **      ***   *****    **     **  **** \n";
    cout<<"**   **   **   **   **   **   **     **    **     *     *   ** * * **  **\n";
    cout<<"*******   **    **  **  **    ***    **    **     *     *   **  *  **  ***\n";
    cout<<"**   **   **     ** ** **     **     **    **     *     *   **     **  **\n";
    cout<<"**   **  ****     **  **      ****   *****   ***   *****    **     **  ****\n";

     int choose , shomare=0;
     string username , password;
     user person[100];
     while(1){

        cout<<"1.Login \n2.Sign Up\n3.Exit \n";
        cin>>choose;
        if(choose==1){
            cout<<"username : ";
            cin>>username;
            cout<<"password : ";
            cin>>password;
               //checking username
               if(person[shomare].check_user(username , person, shomare))
                {

                  while(1)
                  {
                     //checking password
                     if(person[shomare].check_pass(username , password  , person , shomare ))
                     {

                           menu(person , obj , Rate , shomare , counter);
                           break;
                     }
                     else{
                        cout<<"\n----invalid password try again---- \n\n";
                        cout<<"password : ";
                        cin>>password;
                     }

                 }
               }
               else{
                  cout<<"\nIncorrect username \nplease sign up  first!! \n\n";
               }
           }
        else if(choose==2){

              while(1){
               cout<<"username : ";
               cin>>username;
                 //checking for duplicate username
                 if(person[shomare].check_user(username , person, shomare)){
                    cout<<"----This is duplicate username try sth else---- \n";
                 }
                 else{
                    cout<<"password : ";
                    cin>>password;
                    person[shomare].set_username(username);
                    person[shomare].set_password(password);
                    cout<<"\n** ( You signed up successfully!!  ) ** \n You can login now \n\n";
                    shomare++;
                    break;
                 }
              }
        }
        else if(choose==3){
             break;
        }
        else{
           cout<<"\n----Incorrect value please try again---- \n\n";
        }
       // system("cls");
     }

}
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
     file_rating.close();

     UserPart(obj , Rate , counter);
     ofstream R("title.ratings.txt");
       if(R.is_open())
       {
           R<<"tconst\taverageRating\tnumVotes\n";
             for(int i=1; i<counter; i++)
             {
                 R<<Rate[i].get_tconst()<<"\t";
                 R<<Rate[i].get_averageRating()<<"\t";
                 R<<Rate[i].get_numVote()<<"\n";
             }
             R.close();
       }

}