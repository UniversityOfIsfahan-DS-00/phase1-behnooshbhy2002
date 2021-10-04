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
       string get_language(){ return language; }
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
        bool check_user(string users , user person[] , int num)
        {
            for(int i=0; i<num; i++){
                if(users == person[i].get_username()){
                    return true;
                }
            }
            return false;
        }
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
        bool check_vote( string id  ){
             int len = sizeof(list_movie_vote) / sizeof(list_movie_vote[0]);

             for(int i=0; i<len; i++){
                 if(list_movie_vote[i]==id)
                    return true;
             }
             return false;
        }

};
void menu(user person[] , movie obj[] , voteRate rate[] , int shomare , int num_movie)
{
    int choise;
    bool flag=1;
    string id;
    float rating;
    while(flag==1){
        cout<<"1.Show movie's list\n";
        cout<<"2.vote movie\n";
        cout<<"3.Top Ten\n";
        cout<<"4.Voted videos\n";
        cout<<"5.Exit\n";
        cin>>choise;
         switch(choise){
              case 1:
                   cout<<"titleId\tordering\ttitle\tregion\tlanguage\ttypes\tattributes\tisOriginalTitle\n";
                 for(int i=1; i<num_movie; i++){
                   cout<<obj[i].get_titleID()<<"\t"<<obj[i].get_ordring()<<"\t";
                   cout<<obj[i].get_title()<<"\t"<<obj[i].get_region()<<"\t";
                   cout<<obj[i].get_language()<<"\t"<<obj[i].get_types()<<"\t";
                   cout<<obj[i].get_attributes()<<"\t"<<obj[i].get_isOrigin()<<endl;
                   cout<<"------------------------------------------------------------------------------------------------------\n";
                 }
                 break;
              case 2:


                 while(1){
                      cout<<"Enter title id of movie : ";
                      cin>>id;
                      if( person[shomare].check_vote( id ))
                        cout<<"You have voted to this movie before please choose another one\n ";
                      else
                        break;
                   }
                 cout<<"Enter your rating : ";
                   do{
                     cin>>rating;
                       if(rating < 0 || rating > 10)
                         cout<<"Invalid rating try again\nEnter your rating : ";
                   }while(rating < 0 || rating > 10);

                   for(int i=0; i<num_movie; i++){
                      if(rate[i].get_tconst()==id){
                        float r = ( ( rate[i].get_averageRating()*rate[i].get_numVote())+rating ) / (rate[i].get_numVote()+1);
                        rate[i].set_averageRating(r);
                        rate[i].set_numVote(rate[i].get_numVote() + 1);
                        cout<<(rate[i].get_averageRating())<<endl<<(rate[i].get_numVote())<<endl;
                      }
                   }
                   person[shomare].set_listOfMovie( id);
                 break;
              case 3:
                 break;
              case 4:
                 break;
              case 5:
                 flag=0;
                 break;
              default:
                 break;

         }
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
     file_rating.close();


     ///////////////////////////////////////////
     //user part
     int choose , shomare=0;
     string username , password;
     user person[100];
     while(1){

        cout<<"1.login \n2.sign up\n";
        cin>>choose;
        if(choose==1){
            cout<<"username : ";
            cin>>username;
            cout<<"password : ";
            cin>>password;
               if(person[shomare].check_user(username , person, shomare))
                {

                  while(1)
                  {

                     if(person[shomare].check_pass(username , password  , person , shomare ))
                     {

                           menu(person , obj , Rate , shomare , counter);
                           break;
                     }
                     else{
                        cout<<"invalid password try again \n";
                        cout<<"password : ";
                        cin>>password;
                     }

                 }
                // for(int c=1; c<45; c++)
                // cout<<Rate[c].get_tconst()<<"\t"<<Rate[c].get_averageRating()<<"\t"<<Rate[c].get_numVote()<<endl;
               }
               else{
                  cout<<"Incorrect username \nplease sign up  first!! \n";
               }
        }
        else if(choose==2){

              while(1){
               cout<<"username : ";
               cin>>username;
                 if(person[shomare].check_user(username , person, shomare)){
                    cout<<"This is duplicate username try sth else \n";
                 }
                 else{
                    cout<<"password : ";
                    cin>>password;
                    person[shomare].set_username(username);
                    person[shomare].set_password(password);
                    cout<<"You signed up successfully!! \nYou can login now\n";
                    shomare++;
                    break;
                 }
              }
        }
        else{
             cout<<"Incorrect value please try again \n";
        }
     }

}










