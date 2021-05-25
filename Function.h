#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>

using namespace std;

void delete_termin(const char *nazwa_pliku, string termin)
{
  string line;
  ifstream my_file;
  my_file.open(nazwa_pliku);
  ofstream tmp;
  tmp.open("src/lekarzy_txt/temp.txt");
  while(getline(my_file,line))
  {
    if(line!=termin)
    {
      tmp<<line<<endl;
    }
  }
  my_file.close();
  tmp.close();
  remove(nazwa_pliku);
  rename("src/lekarzy_txt/temp.txt", nazwa_pliku);
}

bool czy_termin_istneje(string nazwa_pliku_doktora, string wybrany_termin)
{
  ifstream read_plik;
  read_plik.open(nazwa_pliku_doktora);
  string terminy;
  if(read_plik.is_open())
  {
    while(getline(read_plik,terminy))
    {
        cout<<terminy;
      if(wybrany_termin == terminy)
      {
        return true;
      }
    }
  }
  return false;
}

bool czy_osoba_zarejestowana(string user_login, string user_haslo)
{
    string login, haslo;
    ifstream read;
    read.open("Login/"+user_login+".txt");
    int number_of_line = 0;
    while (number_of_line != 6 && getline(read, login)) 
    {
        number_of_line++;  
    } 
    while (number_of_line!= 7 && getline(read, haslo)) 
    {
        number_of_line++;  
    } 
    // cout<<number_of_line<<endl;
    // cout<<login<<haslo<<endl;
    if(user_login=="" || user_haslo=="")
    {
        return false;
    }
    else if(login == user_login && haslo == user_haslo)
    {
        return true;
    }
    else
    {
        return false;
    }
    
  read.close();  
  return true;
}

int ifstreamFileToWindow(RenderWindow &window, Font &arial, string filename, int size_of_text)
{
    
    std::string line;
    std::ifstream file;
    sf::Text text("", arial, size_of_text);

    file.open(filename); //Set your path here
    if(file.is_open())
    {
        float i=0;
        float it=0;
        while(std::getline(file, line))
        { 
            text.setString(line);
            text.setPosition({20,23+i});
            // if(i>=368)
            // {
            //     text.setPosition({320,22+it});
            //     it+=23;
            // }
            window.draw(text);
            i+=size_of_text;    
        }
    } 
    file.close();
    return 0;
}

string get_imie_from_login_file(string userlogin)
{
    int number_of_line=0;
    ifstream plik;
    string imie;
    plik.open("Login/"+userlogin+".txt");
    if(plik.is_open())
    {
        while (number_of_line != 1 && getline(plik, imie)) 
        {
            number_of_line++;
        } 
        if (imie!="")
        {
            plik.close();
            return imie;
        }
    }   
    plik.close();
    return 0;
}

string get_nazwisko_from_login_file(string userlogin)
{
    int number_of_line=0;
    ifstream plik;
    string nazwisko;
    plik.open("Login/"+userlogin+".txt");
    if(plik.is_open())
    {
        while (number_of_line != 2 && getline(plik, nazwisko)) 
        {
            number_of_line++;
        } 
        if (nazwisko!="")
        {
            plik.close();
            return nazwisko;
        }
    }   
    plik.close();
    return 0;
}


int create_file_for_koszyk(string imie, string nazwisko)
{
    ofstream plik;

    plik.open("src/koszyk/"+imie+"_"+nazwisko+".txt");
    if(plik.is_open())
    {
        plik<<imie+"\n"<<nazwisko+"\n";
    }
    else 
    {
        cout<<"HMMM"<<endl;
    }
    
    
    plik.close();
    return 0;
}

int dodaj_termin_to_koszyk(string imie, string nazwisko, string userlogin, string lekarz, string str_wybrany_termin)
{
    ofstream plik;
    
    plik.open("src/koszyk/"+imie+"_"+nazwisko+".txt", ios::app);
    
    if(plik.is_open())
    {
        plik<<lekarz+" "<<str_wybrany_termin<<'\n';
    }
    else
    {
        cout<<"!!!!!";
    }

    plik.close();
    return 0;
}
