#include<iostream>
#include<string>
using namespace std;
class movie
{
    private :
      string titleID;
      int ordering;
      string title;
      string region;
      string language;
      string type[10];
      string attributes[10];
      bool isOriginalTitle;
    public :
        void set_titleID(string TI){ titleID = TI; }
        void set_ordering(int order){ ordering = order; }
        void set_title(string subject){ title = subject; }
        void set_region(string place){ region = place; }
        void set_language(string lan){ language = lan; }
        void set_type(string arr[10])
        {
          int j=0;
         /*    do{

            type[i]=arr[i];
            i++;

          }while(arr[i]!=nullptr);
          */

           for (auto &i : arr) {
             type[j]=i;
           }
        }

        void set_attributes(string brr[10])
        {
          int j=0;
        /*  do{

            attributes[i]=brr[i];
            i++;

          }while(brr[i]==nullptr);
          */

           for (auto &i : brr) {
             type[j]=i;
           }
        }
        void set_IsOrigin(bool makeSure){ isOriginalTitle = makeSure; }

        string get_titleID()
        {
            return titleID;
        }
        int get_ordering()
        {
            return ordering;
        }
        string get_title()
        {
            return title;
        }
        string get_region()
        {
            return region;
        }
        string get_language()
        {
            return language;
        }
        string get_type()
        {
            return *type;
        }
        string get_attributes()
        {
            return *attributes;
        }
        bool get_IsOrigin()
        {
            return isOriginalTitle;
        }
};
class rating
{
    private :
      string tconst;
      float averageRating;
      int numVotes;
    public :
      void set_tconst(string t){ tconst = t; }
      void set_average(float average){ averageRating = average; }
      void set_numVotes(int num){ numVotes = num; }
      string get_tconst(){ return tconst; }
      float get_average(){ return averageRating; }
      int get_numVotes(){ return numVotes; }

};
int main()
{

}
