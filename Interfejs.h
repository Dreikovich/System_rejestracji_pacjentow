#include <iostream>
#include <fstream>
#include "Textbox.h"
#include "Button.h"
#include "Function.h"

using namespace sf;
using namespace std;

struct scn1
{
	bool imie = false;
	bool nazwisko = false;
    bool PESEL = false;
    bool telefon = false;
    bool mail = false;
    bool login = false;
    bool haslo = false;
};

struct scn3
{
    bool username=false;
    bool pass = false;

};
 

int menu(RenderWindow &window)
{
    sf::Font arial;
    arial.loadFromFile("src/fonts/arial.ttf");

    Button btnpow("Powrot", {165,60},25, Color(254, 254, 182), Color::Black);
    btnpow.setfont(arial);
    btnpow.setPosition({100,600});

    Texture menuTexture1, menuTexture2, menuTexture3, menuTexture4, menuTexture5, menuTexture6, menuTexture7, menuTexture8;
    menuTexture1.loadFromFile("src/images/endokrynolog.png");
    menuTexture2.loadFromFile("src/images/chirurg.png");
    menuTexture3.loadFromFile("src/images/dermatolog.png");
    menuTexture4.loadFromFile("src/images/kardiolog.png");
    menuTexture5.loadFromFile("src/images/neurolog.png");
    menuTexture6.loadFromFile("src/images/okulista.png");
    menuTexture7.loadFromFile("src/images/pediatra.png");
    menuTexture8.loadFromFile("src/images/psychiatra.png");

    
    Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), menu4(menuTexture4), menu5(menuTexture5), menu6(menuTexture6), menu7(menuTexture7),menu8(menuTexture8);
    menu1.setPosition(100, 60);
    menu2.setPosition(95, 122);
    menu3.setPosition(98,180);
    menu4.setPosition(96,240);
    menu5.setPosition(96,303);
    menu6.setPosition(96,360);
    menu7.setPosition(97,420);
    menu8.setPosition(98,480);
    

    bool isMenu=true;
    int menuNum=0;
    
    while(isMenu)
    {
        menuNum = 0;
        while (window.isOpen()) 
        { 
            menu1.setColor(Color::White);
            menu2.setColor(Color::White);
            menu3.setColor(Color::White);
            menu4.setColor(Color::White);
            menu5.setColor(Color::White);
            menu6.setColor(Color::White);
            menu7.setColor(Color::White);
            menu8.setColor(Color::White);
            int x = Mouse::getPosition(window).x;
            int y = Mouse::getPosition(window).y;
            if(x>=100 && x<=300 && y>=60 && y<=95)
            {
                 menu1.setColor(Color(255,253,220));
                 menuNum = 1;
            }
            if(x>=95 && x<=300 && y>=120 && y<=155)
            {
                 menu2.setColor(Color(255,253,220));
                 menuNum = 2;
            }
            if(x>=100 && x<=300 && y>=180 && y<=215)
            {
                 menu3.setColor(Color(255,253,220));
                 menuNum = 3;
            }
            if(x>=100 && x<=300 && y>=240 && y<=280)
            {
                 menu4.setColor(Color(255,253,220));
                 menuNum = 4;
            }
            if(x>=100 && x<=300 && y>=300 && y<=335)
            {
                 menu5.setColor(Color(255,253,220));
                 menuNum = 5;
            }
            if(x>=100 && x<=300 && y>=360 && y<=395)
            {
                 menu6.setColor(Color(255,253,220));
                 menuNum = 6;
            }
            if(x>=100 && x<=300 && y>=420 && y<=455)
            {
                 menu7.setColor(Color(255,253,220));
                 menuNum = 7;
            }
            if(x>=100 && x<=300 && y>=480 && y<=515)
            {
                 menu8.setColor(Color(255,253,220));
                 menuNum = 8;
            }
            if(x>100 && x<=265 && y>=600 && y<=660)
            {
                menuNum=9;
            }



            sf::Event event; 
            while (window.pollEvent(event)) 
            { 
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                    exit(0);
                } 
                if(Mouse::isButtonPressed(Mouse::Left))
                {
                    if(btnpow.isMouseOver(window))
                        {
                            menuNum=9;
                        }
                    isMenu = false;
                    return menuNum;
                }
                if(event.type== sf::Event::MouseMoved)
                {
                    if(btnpow.isMouseOver(window))
                        {
                            btnpow.setBackColor(Color::White);
                        }   
                    else
                    {
                        btnpow.setBackColor(Color(255,254,182));
                    }
                }
               
            } 

            window.clear(sf::Color(105,160,90));
            btnpow.drawTo(window);
            window.draw(menu1);
            window.draw(menu2);
            window.draw(menu3);
            window.draw(menu4);
            window.draw(menu5);
            window.draw(menu6);
            window.draw(menu7);
            window.draw(menu8);
            
            window.display();
		} 
    }
    return 0;
}

int menu2(RenderWindow &window)
{
    Texture menuTexture1, menuTexture2, menuTexture3;
    menuTexture1.loadFromFile("src/images/lekarzy.png");
    menuTexture2.loadFromFile("src/images/koszyk.png");
    menuTexture3.loadFromFile("src/images/powrot.png");
    Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3);
    menu1.setPosition(100, 160);
    menu2.setPosition(100, 252);
    menu3.setPosition(87,344);
    
    bool isMenu=true;
    int menuNum=0;
    
    while(isMenu)
    {
        menuNum = 0;
        while (window.isOpen()) 
        { 
            menu1.setColor(Color::White);
            menu2.setColor(Color::White);
            menu3.setColor(Color::White);
            int x = Mouse::getPosition(window).x;
            int y = Mouse::getPosition(window).y;
            if(x>=100 && x<=300 && y>=160 && y<=225)
            {
                 menu1.setColor(Color(255,253,220));
                 menuNum = 1;
            }
            if(x>=100 && x<=300 && y>=250 && y<=315)//65 pix width new
            {
                 menu2.setColor(Color(255,253,220));
                 menuNum = 2;
            }
            if(x>=87 && x<=300 && y>=340 && y<=405)//65 pix width new
            {
                 menu3.setColor(Color(255,253,220));
                 menuNum = 3;
            }
            sf::Event event; 
            while (window.pollEvent(event)) 
            { 
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                    exit(0);
                } 
                if(Mouse::isButtonPressed(Mouse::Left))
                {
                    isMenu = false;
                    return menuNum;
                }
            } 

            window.clear(sf::Color(105,160,90));
            window.draw(menu1);
            window.draw(menu2);
            window.draw(menu3);
            window.display();
        }
    }
    return 0;
}

int alert(string termin, Font &arial)
{
    RenderWindow window(sf::VideoMode(260,40),"Alert", sf::Style::Close);
    sf::Text alert;
    alert.setFont(arial);
    alert.setCharacterSize(16);
    alert.setFillColor(sf::Color::Black);
    if(termin!="")
    {
        alert.setString(L"Wybrałeś(-aś)  "+termin);
        alert.setPosition({10,10});
        alert.setCharacterSize(16);
    }
    if(termin=="$")
    {
        alert.setString(L"Nieprawidłowy login lub hasło");
        alert.setPosition({23,10});
        alert.setCharacterSize(16);
        cout<<"OK5"<<endl;
    }
    
    if(termin=="#")
    {
        alert.setString(L"Wpisz dane we wszystkie pola");
        alert.setPosition({23,10});
        alert.setCharacterSize(16);
    }
    if(termin=="%")
    {
        alert.setString("Brak terminu");
        alert.setPosition({80,10});
    }
    
    while(window.isOpen())
    {
        sf::Event ev;
        while(window.pollEvent(ev))
        {
            switch(ev.type)
            {
                case Event::Closed: 
                    window.close();
                    break;

            }
        }
        window.clear(sf::Color::White);
        window.draw(alert);
        window.display();
    }
    return 0;
}

int interfejs()
{   
    scn1 scene;
    scn3 scene3;
    int myScene = 1;
    
    // Window
    RenderWindow window(sf::VideoMode(550,700),"System rejestracji pacjentow", sf::Style::Default);
    
    sf::Event ev;

    // set font
    sf::Font arial;
    arial.loadFromFile("src/fonts/arial.ttf");

    // text for rejestracja
    sf::Text imie;
    imie.setFont(arial);
    imie.setString("Imie");
    imie.setPosition({35,50});

    sf::Text nazwisko;
    nazwisko.setFont(arial);
    nazwisko.setString("Nazwisko");
    nazwisko.setPosition({35,110});

    sf:: Text pesel;
    pesel.setFont(arial);
    pesel.setString("PESEL");
    pesel.setPosition({35,170});

    sf:: Text telefon;
    telefon.setFont(arial);
    telefon.setString("Telefon");
    telefon.setPosition({35,230});

    sf:: Text mail;
    mail.setFont(arial);
    mail.setString("E-mail");
    mail.setPosition({35,290});

    sf:: Text login;
    login.setFont(arial);
    login.setString("Login");
    login.setPosition({35,350});

    
    sf:: Text haslo;
    haslo.setFont(arial);
    haslo.setString("Haslo");
    haslo.setPosition({35,410});

    // Text for logowanie

    sf::Text username;
    username.setFont(arial);
    username.setString("Login");
    username.setPosition({60,200});

    sf::Text password;
    password.setFont(arial);
    password.setString(L"Hasło");
    password.setPosition({60,300});

    

    // rectangle for rejestracja
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(290, 25));
    rectangle.setOutlineColor(sf::Color::White);
    rectangle.setFillColor(sf::Color(105,160,90,255));
    rectangle.setOutlineThickness(2.5);
    rectangle.setPosition(220, 60);	

    sf::RectangleShape rectangle2;
    rectangle2.setSize(sf::Vector2f(290, 25));
    rectangle2.setOutlineColor(sf::Color::White);
    rectangle2.setFillColor(sf::Color(105,160,90,255));
    rectangle2.setOutlineThickness(2.5);
    rectangle2.setPosition(220, 120);	

    sf::RectangleShape rectangle3;
    rectangle3.setSize(sf::Vector2f(290, 25));
    rectangle3.setOutlineColor(sf::Color::White);
    rectangle3.setFillColor(sf::Color(105,160,90,255));
    rectangle3.setOutlineThickness(2.5);
    rectangle3.setPosition(220, 180);

    sf::RectangleShape rectangle4;
    rectangle4.setSize(sf::Vector2f(290, 25));
    rectangle4.setOutlineColor(sf::Color::White);
    rectangle4.setFillColor(sf::Color(105,160,90,255));
    rectangle4.setOutlineThickness(2.5);
    rectangle4.setPosition(220, 240);	

    sf::RectangleShape rectangle5;
    rectangle5.setSize(sf::Vector2f(290, 25));
    rectangle5.setOutlineColor(sf::Color::White);
    rectangle5.setFillColor(sf::Color(105,160,90,255));
    rectangle5.setOutlineThickness(2.5);
    rectangle5.setPosition(220, 300);

    sf::RectangleShape rectangle6;
    rectangle6.setSize(sf::Vector2f(290, 25));
    rectangle6.setOutlineColor(sf::Color::White);
    rectangle6.setFillColor(sf::Color(105,160,90,255));
    rectangle6.setOutlineThickness(2.5);
    rectangle6.setPosition(220, 360);

    sf::RectangleShape rectangle7;
    rectangle7.setSize(sf::Vector2f(290, 25));
    rectangle7.setOutlineColor(sf::Color::White);
    rectangle7.setFillColor(sf::Color(105,160,90,255));
    rectangle7.setOutlineThickness(2.5);
    rectangle7.setPosition(220, 420);
    
    // rectangle for logowanie

    sf::RectangleShape rectangle8;
    rectangle8.setSize(sf::Vector2f(290, 25));
    rectangle8.setOutlineColor(sf::Color::White);
    rectangle8.setFillColor(sf::Color(105,160,90,255));
    rectangle8.setOutlineThickness(2.5);
    rectangle8.setPosition(180, 210);

    sf::RectangleShape rectangle9;
    rectangle9.setSize(sf::Vector2f(290, 25));
    rectangle9.setOutlineColor(sf::Color::White);
    rectangle9.setFillColor(sf::Color(105,160,90,255));
    rectangle9.setOutlineThickness(2.5);
    rectangle9.setPosition(180, 310);

    sf::RectangleShape rectangle10;
    rectangle10.setSize(sf::Vector2f(170, 25));
    rectangle10.setOutlineColor(sf::Color::White);
    rectangle10.setFillColor(sf::Color(105,160,90,255));
    rectangle10.setOutlineThickness(2.5);
    rectangle10.setPosition(20, 500);



    Textbox textbox1(20, Color::White, true);
    textbox1.setFont(arial);
    textbox1.setPosition({220,60});
    textbox1.setLimit(true, 25);

    Textbox textbox2(20, Color::White, true);
    textbox2.setFont(arial);
    textbox2.setPosition({220,120});
    textbox2.setLimit(true, 25);

    Textbox textbox3(20, Color::White, true);
    textbox3.setFont(arial);
    textbox3.setPosition({220,180});
    textbox3.setLimit(true, 25);

    Textbox textbox4(20, Color::White, true);
    textbox4.setFont(arial);
    textbox4.setPosition({220,240});
    textbox4.setLimit(true, 25);

    Textbox textbox5(20, Color::White, true);
    textbox5.setFont(arial);
    textbox5.setPosition({220,300});
    textbox5.setLimit(true, 25);

    Textbox textbox6(20, Color::White, true);
    textbox6.setFont(arial);
    textbox6.setPosition({220,360});
    textbox6.setLimit(true, 25);

    Textbox textbox7(20, Color::White, true);
    textbox7.setFont(arial);
    textbox7.setPosition({220,420});
    textbox7.setLimit(true, 25);

    // textbox for logowanie
    Textbox tboxUsername(20, Color::White, true);
    tboxUsername.setFont(arial);
    tboxUsername.setPosition({180,210});
    tboxUsername.setLimit(true, 25);

    Textbox tboxPassword(20, Color::White, true);
    tboxPassword.setFont(arial);
    tboxPassword.setPosition({180,310});
    tboxPassword.setLimit(true, 25);

    Textbox tboxtermin(20,Color::White, true);
    tboxtermin.setFont(arial);
    tboxtermin.setPosition({20,500});
    tboxtermin.setLimit(true, 15);


    Button btn1("Zarejestruj sie", {300,60}, 25, Color(255,254,182), Color::Black);
    btn1.setPosition({220,500});
    btn1.setfont(arial);

    Button btnlogin("Logowanie", {300,100},35, Color(255,254,182), Color::Black);
    btnlogin.setPosition({130,180});
    btnlogin.setfont(arial);

    Button btnregister("Rejestracja", {300,100},35, Color(254, 254, 182), Color::Black);
    btnregister.setPosition({130,350});
    btnregister.setfont(arial);

    Button btnback("Strona glowna", {300,60},25, Color(254, 254, 182), Color::Black);
    btnback.setfont(arial);

    Button btnpowrot("Powrot", {165,60},25, Color(254, 254, 182), Color::Black);
    btnpowrot.setfont(arial);
    btnpowrot.setPosition({20,600});

    Button btnzapisz("Zapisz", {165,60},25, Color(254, 254, 182), Color::Black);
    btnzapisz.setfont(arial);
    btnzapisz.setPosition({200,600});

    // Btn fo logowanie
    Button btnzalogujsie("Zaloguj sie", {300,60},25, Color(254, 254, 182), Color::Black);
    btnzalogujsie.setPosition({180,500});
    btnzalogujsie.setfont(arial);



    while(window.isOpen())
    {
        while(window.pollEvent(ev))
        {
            switch(ev.type)
            {
                case Event::Closed: 
                    window.close();
                    break;
                case Event::KeyPressed:
                    if(ev.key.code == sf::Keyboard::Escape)
                    {
                        window.close();
                    }
                    break;  
                case Event::MouseButtonPressed:
			    
                    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        int x = Mouse::getPosition(window).x;
                        int y = Mouse::getPosition(window).y;   
                        string imie, nazwisko,pesel, telefon, email, login, haslo;
                        // cout<<x<<endl<<y<<endl<<endl;
                        if(myScene==1)
                        {
                            if(btnregister.isMouseOver(window))
                            {
                                myScene=2;
                                btnregister.setBackColor(Color(255,254,182));
                                
                            }

                            if(btnlogin.isMouseOver(window))
                            {

                                myScene=3;
                                btnlogin.setBackColor(Color(255,254,182));
                                
                            }
                        }
                        if(myScene==2)
                        {
                            if(x>=215 && x<=500  && y>=55 && y<= 85) 
                            {
                                scene.imie = true;
                                scene.nazwisko = false;
                                scene.PESEL = false; 
                                scene.telefon=false;
                                scene.mail = false;
                                scene.login = false;
                                scene.haslo = false;
                            }
                            if(x>=215 && x<=500  && y>=115 && y<= 145)
                            {
                                scene.imie = false;
                                scene.nazwisko = true;
                                scene.PESEL = false;
                                scene.telefon=false;
                                scene.mail = false;
                                scene.login = false;
                                scene.haslo = false;
                            }
                                
                            

                            if(x>=215 && x<=500  && y>=175 && y<= 205)
                            {
                                scene.PESEL = true;
                                scene.imie = false;
                                scene.nazwisko = false;
                                scene.telefon=false;
                                scene.mail = false;
                                scene.login = false;
                                scene.haslo = false;
        
                            } 

                            if(x>=215 && x<=500  && y>=235 && y<= 265)
                            {
                                scene.imie = false;
                                scene.nazwisko = false;
                                scene.PESEL = false;
                                scene.telefon=true;
                                scene.mail = false;
                                scene.login = false;
                                scene.haslo = false;
        
                            } 

                            if(x>=215 && x<=500  && y>=295 && y<= 325)
                            {
                                scene.imie = false;
                                scene.nazwisko = false;
                                scene.PESEL = false;
                                scene.telefon=false;
                                scene.mail = true;
                                scene.login = false;
                                scene.haslo = false;
        
                            } 

                            

                            if(x>=215 && x<=500  && y>=355 && y<= 385)
                            {
                                scene.imie = false;
                                scene.nazwisko = false;
                                scene.PESEL = false;
                                scene.telefon=false;
                                scene.mail = false;
                                scene.login = true;
                                scene.haslo = false;
        
                            } 

                            if(x>=215 && x<=500  && y>=415 && y<= 445)
                            {
                                scene.imie = false;
                                scene.nazwisko = false;
                                scene.PESEL = false;
                                scene.telefon=false;
                                scene.mail = false;
                                scene.login = false;
                                scene.haslo = true;
        
                            } 
                            if(btn1.isMouseOver(window))
                            {
                                cout<<"You clicked"<<endl;
                                
                                imie = textbox1.getText();
                                nazwisko = textbox2.getText();
                                pesel = textbox3.getText();
                                telefon = textbox4.getText();
                                email = textbox5.getText();
                                login = textbox6.getText();
                                haslo = textbox7.getText();
                                if(imie=="" || nazwisko=="" || pesel =="" || telefon=="" || email=="" || login=="" || haslo=="")
                                {
                                    alert("#", arial);
                                }
                                else
                                {
                                    cout<<imie<<endl<<nazwisko<<endl<<pesel<<endl<<telefon<<endl<<email<<endl<<login<<endl<<haslo<<endl;

                                    ofstream plik;
                                    plik.open("Login/"+login+".txt");
                                    plik<<imie+"\n"<<nazwisko+"\n"<<pesel<<"\n"<<telefon<<"\n"<<email+"\n"<<login+"\n"<<haslo;
                                    plik.close();
                                    
                                }

                                
                                
                            }


                            if(btnback.isMouseOver(window))
                            {
                                myScene=1;
                                btnback.setBackColor(Color(255,254,182));
                                // kasowanie znaczkow z textbox (czy jest potrzebne?)  
                                textbox1.deleteText();
                                textbox2.deleteText();
                                textbox3.deleteText();
                                textbox4.deleteText();
                                textbox5.deleteText();
                                textbox6.deleteText();
                                textbox7.deleteText();
                                
                            }
                        }

                        if(myScene==3)
                        {
                            if(x>=180 && x<=500  && y>=210 && y<= 245)
                            {   
                                scene3.username = true;
                                scene3.pass = false;
                            }

                            if(x>=180 && x<=500  && y>=310 && y<= 345)
                            {
                                scene3.username = false;
                                scene3.pass = true;
                            }
                            if(btnzalogujsie.isMouseOver(window))
                            {
                                cout<<"You clicked"<<endl;
                                string userlogin = tboxUsername.getText();
                                string userhaslo = tboxPassword.getText();
                                if(czy_osoba_zarejestowana(userlogin, userhaslo)==1)
                                {
                                    cout<<"OK"<<endl;
                                    myScene = 13;
                                    // myScene = 4;
                                    imie = get_imie_from_login_file(userlogin);
                                    nazwisko = get_nazwisko_from_login_file(userlogin);
                                    ifstream plik;
                                    plik.open("src/koszyk/"+imie+"_"+nazwisko+".txt");
                                    if(!plik)
                                    {
                                        create_file_for_koszyk(imie, nazwisko);
                                    }
                                    
                                }
                                else 
                                {
                                    alert("$",arial);
                                    cout<<"not good"<<endl;
                                }
                                btnzalogujsie.setBackColor(Color(255,254,182));
                                
                            }
                            if(btnback.isMouseOver(window))
                            {
                                myScene=1;
                                btnback.setBackColor(Color(255,254,182));
                                tboxUsername.deleteText();
                                tboxPassword.deleteText();

                            }
                        }

                        if(myScene==5 || myScene==6 || myScene==7 || myScene==8|| myScene==9 || myScene==10 || myScene==11 || myScene==12)
                        {
                            if(btnpowrot.isMouseOver(window))
                            {
                                myScene=4;
                                tboxtermin.deleteText();
                                btnpowrot.setBackColor(Color(255,254,182));
                            }
                            if(btnzapisz.isMouseOver(window))
                            {
                                string str_wybrany_termin = tboxtermin.getText();
                                string userlogin = tboxUsername.getText();
                                imie = get_imie_from_login_file(userlogin);
                                nazwisko = get_nazwisko_from_login_file(userlogin);
                                cout<<str_wybrany_termin<<endl;
                                if(myScene==5)
                                {
                                    if(czy_termin_istneje("src/lekarzy_txt/endokrynolog.txt", str_wybrany_termin)==true)
                                    {
                                        cout<<"Wybrales "<<str_wybrany_termin<<endl;
                                        alert(str_wybrany_termin, arial);
                                        dodaj_termin_to_koszyk(imie, nazwisko,userlogin, "Endokrynolog", str_wybrany_termin);
                                        
                                        
                                        delete_termin("src/lekarzy_txt/endokrynolog.txt", str_wybrany_termin);
                                    }
                                    else
                                    {
                                        alert("%",arial);
                                    }
                                }
                                if(myScene==6)
                                {
                                    if(czy_termin_istneje("src/lekarzy_txt/chirurg.txt", str_wybrany_termin)==true)
                                    {

                                        cout<<"Wybrales "<<str_wybrany_termin<<endl;
                                        alert(str_wybrany_termin, arial);
                                        dodaj_termin_to_koszyk(imie, nazwisko,userlogin, "Chirurg", str_wybrany_termin);
                                        delete_termin("src/lekarzy_txt/chirurg.txt", str_wybrany_termin);
                                    }
                                    else
                                    {
                                        alert("%",arial);
                                    }
                                }

                                if(myScene==7)
                                {
                                    if(czy_termin_istneje("src/lekarzy_txt/dermatolog.txt", str_wybrany_termin)==true)
                                    {
                                        cout<<"Wybrales "<<str_wybrany_termin<<endl;
                                        alert(str_wybrany_termin, arial);
                                        dodaj_termin_to_koszyk(imie, nazwisko,userlogin, "Dermatolog", str_wybrany_termin);
                                        delete_termin("src/lekarzy_txt/dermatolog.txt", str_wybrany_termin);
                                    }
                                    else
                                    {
                                        alert("%",arial);
                                    }
                                }

                                if(myScene==8)
                                {
                                    if(czy_termin_istneje("src/lekarzy_txt/kardiolog.txt", str_wybrany_termin)==true)
                                    {
                                        cout<<"Wybrales "<<str_wybrany_termin<<endl;
                                        alert(str_wybrany_termin, arial);
                                        dodaj_termin_to_koszyk(imie, nazwisko,userlogin, "Kardiolog", str_wybrany_termin);
                                        delete_termin("src/lekarzy_txt/kardiolog.txt", str_wybrany_termin);
                                    }
                                    else
                                    {
                                        alert("%",arial);
                                    }
                                }

                                if(myScene==9)
                                {
                                    if(czy_termin_istneje("src/lekarzy_txt/neurolog.txt", str_wybrany_termin)==true)
                                    {
                                        cout<<"Wybrales "<<str_wybrany_termin<<endl;
                                        alert(str_wybrany_termin, arial);
                                        dodaj_termin_to_koszyk(imie, nazwisko,userlogin, "Neurolog", str_wybrany_termin);
                                        delete_termin("src/lekarzy_txt/neurolog.txt", str_wybrany_termin);
                                    }
                                    else
                                    {
                                        alert("%",arial);
                                    }
                                }

                                if(myScene==10)
                                {
                                    if(czy_termin_istneje("src/lekarzy_txt/okulista.txt", str_wybrany_termin)==true)
                                    {
                                        cout<<"Wybrales "<<str_wybrany_termin<<endl;
                                        alert(str_wybrany_termin, arial);
                                        dodaj_termin_to_koszyk(imie, nazwisko,userlogin, "Okulista", str_wybrany_termin);
                                        delete_termin("src/lekarzy_txt/okulista.txt", str_wybrany_termin);
                                    }
                                    else
                                    {
                                        alert("%",arial);
                                    }
                                }

                                if(myScene==11)
                                {
                                    if(czy_termin_istneje("src/lekarzy_txt/pediatra.txt", str_wybrany_termin)==true)
                                    {
                                        cout<<"Wybrales "<<str_wybrany_termin<<endl;
                                        alert(str_wybrany_termin, arial);
                                        dodaj_termin_to_koszyk(imie, nazwisko,userlogin, "Pediatra", str_wybrany_termin);
                                        delete_termin("src/lekarzy_txt/pediatra.txt", str_wybrany_termin);
                                    }
                                    else
                                    {
                                        alert("%",arial);
                                    }
                                }

                                if(myScene==12)
                                {
                                    if(czy_termin_istneje("src/lekarzy_txt/psychiatra.txt", str_wybrany_termin)==true)
                                    {
                                        cout<<"Wybrales "<<str_wybrany_termin<<endl;
                                        alert(str_wybrany_termin, arial);
                                        dodaj_termin_to_koszyk(imie, nazwisko,userlogin, "Psychiatra", str_wybrany_termin);
                                        delete_termin("src/lekarzy_txt/psychiatra.txt", str_wybrany_termin);
                                    }
                                    else
                                    {
                                        alert("%",arial);
                                    }
                                }
                                
                            }
                        }
                        if(myScene==14)
                        {
                            if(btnpowrot.isMouseOver(window))
                            {
                                myScene=13;
                                btnpowrot.setBackColor(Color(255,254,182));
                            }
                        }
                    }
                    break;
                case Event::TextEntered:
                    if(myScene==2)
                    {
                        if(scene.imie == true)
                        {
                            textbox1.typedOn(ev);
                        }
                        if(scene.nazwisko == true)
                        {
                            textbox2.typedOn(ev);
                        }
                        if(scene.PESEL == true)
                        {
                            textbox3.typedOn(ev);
                        }
                        if(scene.telefon == true)
                        {
                            textbox4.typedOn(ev);
                        }
                        if(scene.mail == true)
                        {
                            textbox5.typedOn(ev);
                        }
                        if(scene.login == true)
                        {
                            textbox6.typedOn(ev);
                        }
                        if(scene.haslo == true)
                        {
                            textbox7.typedOn(ev);
                        }
                        break;
                    }
                    if(myScene==3)
                    {
                        if(scene3.username==true)
                        {
                            tboxUsername.typedOn(ev);
                        }
                        if(scene3.pass == true)
                        {
                            tboxPassword.typedOn(ev);
                        }
                        
                    }
                    if(myScene==5 || myScene==6 || myScene==7 || myScene==8 || myScene==9 || myScene==10 || myScene==11 || myScene==12)
                    {
                        tboxtermin.typedOn(ev); 
                    }
                    
                    
                case Event::MouseMoved:
                    if(myScene==1)
                    {
                        if(btnlogin.isMouseOver(window))
                        {
                            btnlogin.setBackColor(Color::White);
                        }   
                        else
                        {
                            btnlogin.setBackColor(Color(255,254,182));
                        }
                        if(btnregister.isMouseOver(window))
                        {
                            btnregister.setBackColor(Color::White);
                        }   
                        else
                        {
                            btnregister.setBackColor(Color(255,254,182));
                        }

                    }
                    if(myScene==2)
                    {
                        if(btn1.isMouseOver(window))
                        {
                            btn1.setBackColor(Color::White);
                        }    
                        else 
                        {
                            btn1.setBackColor(Color(255,254,182));
                        }
                        if(btnback.isMouseOver(window))
                        {
                            btnback.setBackColor(Color::White);
                        }    
                        else 
                        {
                            btnback.setBackColor(Color(255,254,182));
                        }
                        
                    }
                    if(myScene==3)
                    {
                        if(btnzalogujsie.isMouseOver(window))
                        {
                            btnzalogujsie.setBackColor(Color::White);
                        }    
                        else
                        {
                            btnzalogujsie.setBackColor(Color(255,254,182));
                        }
                        if(btnback.isMouseOver(window))
                        {
                            btnback.setBackColor(Color::White);
                        }    
                        else
                        {
                            btnback.setBackColor(Color(255,254,182));
                        }
                        
                    }
                    if(myScene==5 || myScene==6 || myScene==7 || myScene==8|| myScene==9 || myScene==10 || myScene==11 || myScene==12 || myScene==14)
                    {
                        if(btnpowrot.isMouseOver(window))
                        {
                            btnpowrot.setBackColor(Color::White);
                        }    
                        else
                        {
                            btnpowrot.setBackColor(Color(255,254,182));
                        }
                        if(btnzapisz.isMouseOver(window))
                        {
                            btnzapisz.setBackColor(Color::White);
                        }    
                        else
                        {
                            btnzapisz.setBackColor(Color(255,254,182));
                        }
                    }
                    
                    break;
            }
        }

        window.clear(sf::Color(105,160,90)); // Clear old frame

        // Draw app

        // myScene=1 - strona glowna(logowanie, rejestracja)
        if (myScene==1)
        {
            btnlogin.drawTo(window);
            btnregister.drawTo(window);
        }
        // myScene=2 - rejestracja
        if(myScene==2)
        {
            btnback.setPosition({220,600});
            window.draw(imie);
            window.draw(nazwisko);
            window.draw(pesel);
            window.draw(telefon);
            window.draw(mail);
            window.draw(login);
            window.draw(haslo);
            window.draw(rectangle);
            window.draw(rectangle2);
            window.draw(rectangle3);
            window.draw(rectangle4);
            window.draw(rectangle5);
            window.draw(rectangle6);
            window.draw(rectangle7);
            textbox1.drawTo(window);
            textbox2.drawTo(window);
            textbox3.drawTo(window);
            textbox4.drawTo(window);
            textbox5.drawTo(window);
            textbox6.drawTo(window);
            textbox7.drawTo(window);
            btn1.drawTo(window);
            btnback.drawTo(window);
        }
        // myScene=3 - logowanie
        if(myScene==3)
        {
            btnback.setPosition({180,600});
            window.draw(username);
            window.draw(password);
            window.draw(rectangle8);
            window.draw(rectangle9);
            tboxUsername.drawTo(window);
            tboxPassword.drawTo(window);
            btnzalogujsie.drawTo(window);
            btnback.drawTo(window);
        
        }

        if(myScene==13)
        {
            int num;
            num = menu2(window);
            cout<<num;
            switch (num)
            {
                case 1:
                    myScene=4;
                    break;
                case 2:
                    myScene=14;
                    break;    
                case 3:
                    // tboxUsername.deleteText();
                    // tboxPassword.deleteText();
                    myScene=3;
                    break;    
            }
        }
        
        
        // list of doctors
        if(myScene==4)
        {
            int num;
            num = menu(window);
            
            cout<<num;
           
            switch (num)
            {
                case 1:
                    myScene =5;
                    break;
                case 2:
                    myScene = 6;
                    break;
                case 3:
                    myScene = 7;
                    break;
                case 4:
                    myScene = 8;
                    break;
                case 5:
                    myScene = 9;
                    break;
                case 6:
                    myScene = 10;
                    break;  
                case 7:
                    myScene = 11;
                    break;  
                case 8:
                    myScene = 12;
                    break;   
                case 9:
                    myScene = 13;
                    break;       
            }
            
        }
        
        if(myScene==5)
        {
            
            window.clear(sf::Color(105,160,90));
            ifstreamFileToWindow(window,arial,"src/lekarzy_txt/endokrynolog.txt",22); // доработать  выбор термина
            window.draw(rectangle10);
            tboxtermin.drawTo(window);
            btnpowrot.drawTo(window);
            btnzapisz.drawTo(window);
        }
        if(myScene==6)
        {
            window.clear(sf::Color(105,160,90));
            ifstreamFileToWindow(window,arial,"src/lekarzy_txt/chirurg.txt",22); 
            window.draw(rectangle10);
            tboxtermin.drawTo(window);
            btnpowrot.drawTo(window);
            btnzapisz.drawTo(window);
            
        }
        if(myScene==7)
        {
            window.clear(sf::Color(105,160,90));
            ifstreamFileToWindow(window,arial,"src/lekarzy_txt/dermatolog.txt",22); 
            window.draw(rectangle10);
            tboxtermin.drawTo(window);
            btnpowrot.drawTo(window);
            btnzapisz.drawTo(window);
        }
        if(myScene==8)
        {
            window.clear(sf::Color(105,160,90));
            ifstreamFileToWindow(window,arial,"src/lekarzy_txt/kardiolog.txt",22);
            window.draw(rectangle10);
            tboxtermin.drawTo(window);
            btnpowrot.drawTo(window);
            btnzapisz.drawTo(window);
        }
        if(myScene==9)
        {
            window.clear(sf::Color(105,160,90));
            ifstreamFileToWindow(window,arial,"src/lekarzy_txt/neurolog.txt",22);
            window.draw(rectangle10);
            tboxtermin.drawTo(window);
            btnpowrot.drawTo(window);
            btnzapisz.drawTo(window);
        }
        if(myScene==10)
        {
            window.clear(sf::Color(105,160,90));
            ifstreamFileToWindow(window,arial,"src/lekarzy_txt/okulista.txt",22);
            window.draw(rectangle10);
            tboxtermin.drawTo(window);
            btnpowrot.drawTo(window);
            btnzapisz.drawTo(window);
        }
        if(myScene==11)
        {
            window.clear(sf::Color(105,160,90));
            ifstreamFileToWindow(window,arial,"src/lekarzy_txt/pediatra.txt",22);
            window.draw(rectangle10);
            tboxtermin.drawTo(window);
            btnpowrot.drawTo(window);
            btnzapisz.drawTo(window);
        }
        if(myScene==12)
        {
            window.clear(sf::Color(105,160,90));
            ifstreamFileToWindow(window,arial,"src/lekarzy_txt/psychiatra.txt",22);
            window.draw(rectangle10);
            tboxtermin.drawTo(window);
            btnpowrot.drawTo(window);
            btnzapisz.drawTo(window);
        }
        if(myScene==14)
        {
            window.clear(sf::Color(105,160,90));
            string userlogin = tboxUsername.getText();
            string imie = get_imie_from_login_file(userlogin);
            string nazwisko = get_nazwisko_from_login_file(userlogin);
            string path = "src/koszyk/"+imie+"_"+nazwisko+".txt";
            ifstreamFileToWindow(window,arial,path, 36);
            btnpowrot.drawTo(window);
        }
        window.display();
    }
    return 0;
}