#include <iostream>
#include<string.h>
#include<stdlib.h>
#define GAME 1000

using namespace std;

class Game
{

    public:
            int jedihealth = GAME;
            int vaderhealth = GAME;
            int troops = (GAME/2);
            int crew = (GAME-600);
            int shiphealth = (GAME/10);
            int vadershiphealth = (GAME-910);
            int jedifrihealth = (GAME-850);
            int myspower = (GAME/100);

            virtual void victory(){}
            virtual void usetheforce(){}
    //        virtual int endgame();

};

class Jedi : public Game
{
    public:

        void shootgun()
        {
            vaderhealth = (vaderhealth-(GAME/2))+troops;
            myspower = myspower + (GAME/10);
        }

        void usebluesaber()
        {
            vaderhealth = (vaderhealth/2);
        }

        void usetheforce()
        {
            myspower = myspower + 20;
            shiphealth = shiphealth + 20;
        }

        void victory()
        {
            cout<<"\nLuke Skywalker: There should be balance in the universe! I am happy that it was possible to deafeat the Imperial fleet and bring peace to the universe!"<<endl;
            cout<<"\nI thank all the crew members and the base for all the support! Its always a team work!"<<endl;


        }



};



class DarthVader : public Game
{
    public:

        void usetheforce()
        {
            jedihealth = jedihealth - (GAME/550);
            jedifrihealth = jedifrihealth - (GAME-950);
        }

        void useredsaber()
        {
            jedihealth = (jedihealth/2);
        }

        void victory()
        {
            cout<<"\n(heavy breathing)...Yess...I have won it. I will deploy more droids across the universe and gain more control! This mission would not have been possible without me!"<<endl;


        }


};

class Stormtrooper : public Game
{
    public:

    void attackBase()
    {
        shiphealth = shiphealth - 20;
        crew = crew - 30;
    }


};

class Base : public Game
{

    public:


    void shutdownpower()
    {
        shiphealth = shiphealth + 10;
    }

    void shootenemy()
    {
        vadershiphealth = vadershiphealth - 20;
        troops = troops - (GAME/10);
    }


};


int main()
{

Jedi j;
Game *p;
DarthVader d;
Stormtrooper s;
Base b;

 cout <<"\t\t\t\tENTER TO THE STAR WARS UNIVERSE!!\n\n" << endl;
    cout<<"\t\t\t\tThe empire strikes back!!\n\n\n\n";
    cout<<"YOU ARE THE CHOSEN JEDI"<<endl;
    cout<<"Its been three years since the Death Star has been destructed. The Rebels, led by Princess Leia, have set up their new base on the ice planet Hoth. "<<endl;

    cout<<"The Imperial fleet, led by Darth Vader, continues to hunt fot thr Rebels' new base by dispatching probe droids across the galaxy"<<endl;
    cout<<"The galactic empire, under the leadership of the villainous Darth Vader and the Emperor is in pursuit of Luke Skywalker and the rest of the Rebel Alliance."<<endl;
    cout<<"When Vader captures Luke's friends, Luke must decide whether to complete his training and become a full jedi or to confront Vader and save them."<<endl;
    cout<<"\nLuke Skywalker goes to rescue his friends from Darth Vader who is actually his father! "<<endl;
    cout<<"Since Luke is a skywalker, he decides to fight the Dark Emperor!"<<endl;

    cout<<"psst...this is a 2-player game, so decide who you want to be. Jedi gets to play first!"<<endl;

    cout<<"\t\t*******May the Force be with you!!******"<<endl;

while((d.jedihealth>0 || s.shiphealth < 1) && (j.vaderhealth>0 || b.vadershiphealth < 1))
{

cout<<"\n\n1.Use your gun!\t2.Use the lightsaber\t3.Use the force\t4.Get support from the base\t5.Predict\n";
cout<<"Luke! Choose your weapon!: ";
int luke;
cin>>luke;
    switch(luke)
    {
        case 1: j.shootgun();
                break;
        case 2: j.usebluesaber();
                break;
        case 3: j.usetheforce();
                d.jedifrihealth = d.jedifrihealth +20;
                    break;
        case 4: b.shootenemy();
                break;
        case 5:
        default: if(d.jedihealth > j.vaderhealth)
                    cout<<"\n****Jedi eventually will win!****"<<endl;
                  else
                    cout<<"\n****Darth vader will eventually win!****"<<endl;

                return 0;
                break;

    }


 cout<<"\n1.Use the force\t2.Use the saber\t3.Call in the stormtroopers\t4.Predict\n";
 cout<<"Darth Vader! Whats your move?!: ";
 int darth;
 cin>>darth;
        switch(darth)
        {
            case 1: d.usetheforce();
                    j.vaderhealth = (j.vaderhealth - j.myspower);
                    j.myspower = j.myspower - (d.jedifrihealth/2);

                    break;
            case 2: d.useredsaber();
                    break;
            case 3: s.attackBase();
                    b.shutdownpower();
                    break;
            case 4:
            default: if(d.jedihealth < j.vaderhealth)
                        cout<<"\n****Darth eventually will win!****"<<endl;
                    else
                        cout<<"\n****Jedi vader will eventually win****"<<endl;

                    return 0;
                    break;
        }

            cout<<"\n\n";

    if(d.jedihealth < 1)
        cout<<"\nJedi's health: :X";
    else
        cout<<"\nJedi's health: "<<d.jedihealth;


        if(j.vaderhealth < 1)
            cout<<"\t\tDarth Vader health: :X"<<endl;
        else
            cout<<"\t\tDarth Vader health: "<<j.vaderhealth<<endl;



    if(s.shiphealth < 1 )
    {
     cout<<"\nShip health:**BOOM**";
        cout<<"\nJedi friends health: :X";
        cout<<"\ncCrew on board: :X";
    }

    else
    {
    cout<<"\nShip health: "<<s.shiphealth;
    if(d.jedifrihealth < 1)
        cout<<"\nJedi's friends health: :X";
    else
        cout<<"\nJedi's friends health: "<<d.jedifrihealth;
        if(s.crew < 1)
            cout<<"\nCrew on board: :X";
        else
            cout<<"\nCrew on board: "<<s.crew;
    }




            if(b.vadershiphealth < 1)
            {
             cout<<"\t\tVader ship health:**BOOM*"<<endl;
             cout<<"\t\t\t\t\tTroops: :X"<<endl;
            }
            else
            {
             cout<<"\t\tVader ship health:"<<b.vadershiphealth<<endl;
             cout<<"\t\t\t\t\tTroops: "<<b.troops<<endl;
            }
    cout<<"Jedi Mystery Power: "<<j.myspower;



    if(d.jedihealth < 1 || s.shiphealth < 1)
    {
        cout<<"\n\n*****Darth Vader...you rule the Empire!*****"<<endl;
        p = &d;
        p->victory();
        goto ask;

    }

    else if(j.vaderhealth < 1 || b.vadershiphealth < 1)
    {
        cout<<"\n\n*****Luke Skywalker! The Universe is safe!*****"<<endl;
        p = &j;
        p->victory();
        goto ask;

    }

}


       // system("PAUSE");
       ask:
        cout<<"\n\nDo You want to continue playing? (Y/N): "<<endl;
        char c;
        cin>>c;
        if(c == 'Y' || c == 'y')
            return main();
        else
            return 0;





}




















