#include <simplecpp>
#include<sstream>
#include<string>
#include "shooter.h"
#include "bubble.h"
using namespace std;

/* Simulation Vars */
const double STEP_TIME = 0.02;

/* Game Vars */
const int PLAY_Y_HEIGHT = 450;
const int LEFT_MARGIN = 70;
const int TOP_MARGIN = 20;
const int BOTTOM_MARGIN = (PLAY_Y_HEIGHT+TOP_MARGIN);
const int RIGHT_MARGIN = 400;
int n;


void move_bullets(vector<Bullet> &bullets){
    // move all bullets
    for(unsigned int i=0; i<bullets.size(); i++){
        if(!bullets[i].nextStep(STEP_TIME)){
            bullets.erase(bullets.begin()+i);
        }
    }
}

void move_bubbles(vector<Bubble> &bubbles){
    // move all bubbles
    for (unsigned int i=0; i < bubbles.size(); i++)
    {
        bubbles[i].nextStep(STEP_TIME);
    }
}
double score1 = 0;
bool clash(vector<Bubble> &bubbles, vector<Bullet> &bullets)
{
    // double radius = bubbles.get_radius();
    for (unsigned int i = 0; i < bubbles.size(); i++)
    {
        for (unsigned int j = 0; j < bullets.size(); j++)
        {  
           if ( bubbles[i].get_radius() == 20){
            if (bubbles[i].get_center_x() - 20 < bullets[j].get_center_x() && bubbles[i].get_center_x() + 20 > bullets[j].get_center_x() && bubbles[i].get_center_y() - 20 < bullets[j].get_center_y() && bubbles[i].get_center_y() + 20 > bullets[j].get_center_y())
            {
                if (bubbles[i].get_radius() == 10)
                {
                    bullets.erase(bullets.begin()+j);
                    bubbles.erase(bubbles.begin()+i);
                    // return true;
                    score1 = score1 + 1;
                    return true;
                }
                else
                
                bubbles.push_back(Bubble(bubbles[i].get_center_x(), bubbles[i].get_center_y(), BUBBLE_RADIUS_THRESHOLD, -200, 100, COLOR(255,105,180)));
                bubbles.push_back(Bubble(bubbles[i].get_center_x(), bubbles[i].get_center_y(), BUBBLE_RADIUS_THRESHOLD, 200, 100, COLOR(255, 105,180)));
                bullets.erase(bullets.begin()+j);
                bubbles.erase(bubbles.begin()+i);
                // return true;
                score1 = score1 + 1;
                return true;
            }
           }
           else if ( bubbles[i].get_radius() == 10){
               if (bubbles[i].get_center_x() - 10 < bullets[j].get_center_x() && bubbles[i].get_center_x() + 10 > bullets[j].get_center_x() && bubbles[i].get_center_y() - 10 < bullets[j].get_center_y() && bubbles[i].get_center_y() + 10 > bullets[j].get_center_y())
               {
                   bullets.erase(bullets.begin()+j);
                    bubbles.erase(bubbles.begin()+i);
                    // return true;
                    score1 = score1 + 1;
                    return true;
               }
               
           }
        }
        
    }
    if (bubbles.size() == 0)
    {
        string show("Congratulations!!");

        Text char2(250, 250, show);char2.setColor(COLOR(100, 100, 100));
        char2.imprint();
        
            }
    
}
double h = 51;
double t = 0;
bool clasher(vector<Bubble> &bubbles, Shooter &shoot)
{
    for (unsigned int i = 0; i < bubbles.size(); i++)
    {
        if ((sqrt((shoot.get_head_center_x() - bubbles[i].get_center_x())*(shoot.get_head_center_x() - bubbles[i].get_center_x()) +(shoot.get_head_center_y() - bubbles[i].get_center_y())*(shoot.get_head_center_y() - bubbles[i].get_center_y())) <= bubbles[i].get_radius() + shoot.get_head_radius()) || ((abs(shoot.get_body_center_x() - bubbles[i].get_center_x()) <= (shoot.get_body_width() / 2.0 + bubbles[i].get_radius())) && (abs(shoot.get_body_center_y() - bubbles[i].get_center_y()) <= (shoot.get_body_height() / 2.0 + bubbles[i].get_radius())))) 
        {
            
            bubbles.push_back(Bubble(bubbles[i].get_center_x(), bubbles[i].get_center_y(),bubbles[i].get_radius(), -bubbles[i].get_vx(), -bubbles[i].get_vy(), COLOR(255, 105, 180)));
            h = h - 1;
            bubbles.erase(bubbles.begin()+ i);
             return true;

        }
        
    }
  
// bubbles.get_vx() = 0;
// bubbles.get_vy() = 0;
}
int level_ = 1;
void level2(vector<Bubble> &bubbles, vector<Bullet> &bullets){
    if (bubbles.size() == 0)
    {
        ++level_;
        h = 51;
        score1 = 0;
        t = 0;
        Text cong4(250, 250, "LEVEL 1 COMPLETED");
        wait(2);
        Text cong(250, 325, "Level 2");
        wait(2);
        for (int i = 0; i < bullets.size(); i++)
        {
            bullets.erase(bullets.begin()+i);
        }
        bubbles.push_back(Bubble(WINDOW_X/2.0, BUBBLE_START_Y, BUBBLE_DEFAULT_RADIUS, -(2*BUBBLE_DEFAULT_VX), -(2*BUBBLE_DEFAULT_VY), COLOR(100, 200, 100)));
        bubbles.push_back(Bubble(WINDOW_X/2.0, BUBBLE_START_Y, BUBBLE_DEFAULT_RADIUS, (2*BUBBLE_DEFAULT_VX), (2*BUBBLE_DEFAULT_VY), COLOR(100, 200, 100)));
    }
    
}
void level3(vector<Bubble> &bubbles, vector<Bullet> &bullets){
    if (bubbles.size() == 0)
    {
        ++level_;
        h = 51;
        score1 = 0;
        t = 0;
        Text cong2(250, 250, "LEVEL 2 COMPLETED");
        wait(2);
        Text cong3(250, 325, "Level 3");
        wait(2);
        for (int i = 0; i < bullets.size(); i++)
        {
            bullets.erase(bullets.begin()+i);
        }
        bubbles.push_back(Bubble(WINDOW_X/2.0, BUBBLE_START_Y, BUBBLE_DEFAULT_RADIUS, 3*BUBBLE_DEFAULT_VX, -(3*BUBBLE_DEFAULT_VY), COLOR(100, 100, 200)));
        bubbles.push_back(Bubble(WINDOW_X/4.0, BUBBLE_START_Y, BUBBLE_DEFAULT_RADIUS, -3*BUBBLE_DEFAULT_VX, (3*BUBBLE_DEFAULT_VY), COLOR(100, 100, 200)));
        bubbles.push_back(Bubble(WINDOW_X/2.0, BUBBLE_START_Y, BUBBLE_DEFAULT_RADIUS, -3*BUBBLE_DEFAULT_VX, (3*BUBBLE_DEFAULT_VY), COLOR(100, 100, 200)));
        bubbles.push_back(Bubble(WINDOW_X/4.0, BUBBLE_START_Y, BUBBLE_DEFAULT_RADIUS, 3*BUBBLE_DEFAULT_VX, -(3*BUBBLE_DEFAULT_VY), COLOR(100, 100, 200)));
    }
    
}


vector<Bubble> create_bubbles()
{
    // create initial bubbles in the game
    vector<Bubble> bubbles;
    bubbles.push_back(Bubble(WINDOW_X/2.0, BUBBLE_START_Y, BUBBLE_DEFAULT_RADIUS, -BUBBLE_DEFAULT_VX, -BUBBLE_DEFAULT_VY, COLOR(255,105,180)));
    // bubbles.push_back(Bubble(WINDOW_X/2.0, BUBBLE_START_Y, BUBBLE_DEFAULT_RADIUS, BUBBLE_DEFAULT_VX, BUBBLE_DEFAULT_VY, COLOR(255,105,180)));
    // bubbles.push_back(Bubble(WINDOW_X/4.0, BUBBLE_START_Y, BUBBLE_DEFAULT_RADIUS, BUBBLE_DEFAULT_VX, -BUBBLE_DEFAULT_VY, COLOR(255,105,180)));
    // bubbles.push_back(Bubble(WINDOW_X/4.0, BUBBLE_START_Y, BUBBLE_DEFAULT_RADIUS, BUBBLE_DEFAULT_VX, BUBBLE_DEFAULT_VY, COLOR(255,105,180)));
    return bubbles;
}


int main()
{   string name;
    cout<<"Please enter your name: ";
    cin>>name;
    initCanvas("Bubble Trouble", WINDOW_X, WINDOW_Y);

    Line b1(0, PLAY_Y_HEIGHT, WINDOW_X, PLAY_Y_HEIGHT);
    b1.setColor(COLOR(0, 0, 255));
    Line b2(0, 40, WINDOW_X, 40);
    b2.setColor(COLOR(0, 0, 255));
    Text hari(250, TOP_MARGIN, name);
    hari.setColor(COLOR(255, 0, 0));
    

    string msg_cmd("Cmd: _");
    Text charPressed(LEFT_MARGIN, BOTTOM_MARGIN, msg_cmd);

    string time("TIME (50): _");
    Text char1Pressed(LEFT_MARGIN, TOP_MARGIN, time);
    char1Pressed.setColor(COLOR(0, 0, 255));
    string level("HEALTH: _/3");
            Text char2Pressed(RIGHT_MARGIN, TOP_MARGIN, level);
    
    string health("LEVEL _");
    Text Pressed(250, BOTTOM_MARGIN, health);
    string score("SCORE: _");
    Text char3Pressed(RIGHT_MARGIN, BOTTOM_MARGIN, score);
    
    

    // Intialize the shooter
    Shooter shooter(SHOOTER_START_X, SHOOTER_START_Y, SHOOTER_VX);

    // Initialize the bubbles
    vector<Bubble> bubbles = create_bubbles();

    // Initialize the bullets (empty)
    vector<Bullet> bullets;
    // vector<Shooter> x;
    XEvent event;
    // Main game loop
    // int d = 51;
    // int i = 48;
    int m = 49;
    while (true)

    {  
        int s = t;
        ostringstream strl;
        strl << s;
        string geek = strl.str();
        time.append(geek);
        char1Pressed.setMessage(time);
        time.erase(10);
        t = t + 0.04;
// char h = charFromEvent(event);

        health[health.length() - 1] = int(char(m));
        Pressed.setMessage(health);

        if (s == 50)
        {
          Text timeout(250, 250, "Time Over.. Try Again " + name);
            wait(10);
            break;  
        }
        // int m = 0;
        if (bubbles.size() == 0)
        {
            if (m == 49)
            {
                level2(bubbles, bullets);
                m++;
            }
            else if (m == 50)
            {
                level3(bubbles, bullets);
                m++;
            }
            else if (m == 51)
            {
                Text won(250, 250, "LEVEL 3 COMPLETED");
                wait(2);
                Text won1(250, 325, "CHICKEN DINNER");
                won1.setColor(COLOR(255, 0, 0));
                wait(5);
                break;
            }
            
        }
        
        level[level.length() - 3] = double(char(h));
        char2Pressed.setMessage(level);

        bool pendingEvent = checkEvent(event);
    
        if (pendingEvent)
        {   
            // Get the key pressed
            char c = charFromEvent(event);
            msg_cmd[msg_cmd.length() - 1] = c;
            charPressed.setMessage(msg_cmd);
            
            
            
            // Update the shooter
            if(c == 'a')
                shooter.move(STEP_TIME, true);
            else if(c == 'd')
                shooter.move(STEP_TIME, false);
            else if(c == 'w')
                bullets.push_back(shooter.shoot());
            else if(c == 'q')
                return 0;
    
        }

        if (h - 48 <= 0)
        {
            Text over(250, 250, "Game Over");
            wait(10);
            break;
        }
        
        // Update the bubbles
        move_bubbles(bubbles);

        // Update the bullets
        move_bullets(bullets);
        clash(bubbles, bullets);

        

        clasher(bubbles, shooter);

        ostringstream strl1;
        strl1 << score1;
        string geek1 = strl1.str();
        score.append(geek1);
        char3Pressed.setMessage(score);
        score.erase(7);

        // score[score.length() - 1] = double(char(score1));
        // char3Pressed.setMessage(score);

        wait(STEP_TIME);

    }
    
}
