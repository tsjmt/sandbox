#include "iostream"
using namespace std;

struct i2c{
    int pin;
    i2c(int _pin):pin(_pin){};
    void write(int x){cout<<"i2c_write "<<x<<endl;};
};

struct i2c_emulate{
    i2c_emulate(){};
    void write(int x){cout<<"i2c emulate "<<x<<endl;};
};

template <class port_t>
struct display{
    port_t& port; 
    display(port_t& _port):port(_port){};
    void set(int x, int y){port.write(x+y);};
};

struct display_emulate{
    display_emulate(){};
    void set(int x, int y){cout<<"display emulate "<<x<<","<<y<<endl;};
};

template <class disp_t>
struct graphic{
    disp_t& disp; 
    graphic(disp_t& _disp):disp(_disp){};
    void draw(){disp.set(1,2);};
};

int main(){
    i2c i2c_hw(0);
    i2c_emulate i2c_sw;
    i2c_hw.write(2);
    i2c_sw.write(2);

    display disp_hw(i2c_hw);
    display_emulate disp_sw;
    disp_hw.set(2,4);
    disp_sw.set(2,4);

    graphic graph_hw(disp_hw);
    graphic graph_sw(disp_sw);
    graph_hw.draw();
    graph_sw.draw();

    return 0;
}

