#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Vswitch.h"
#include <verilated_vcd_c.h>

vluint64_t sc_time = 0;
double sc_time_stamp()
{
		return sc_time;
}
int main(int argc, char** argv, char** env){
	VerilatedContext* contextp = new VerilatedContext;
	contextp->commandArgs(argc,argv);
	// vcd
	Verilated::traceEverOn(true);
	VerilatedVcdC* m_trace = new VerilatedVcdC;
	Vswitch* top = new Vswitch{contextp};
	top->trace(m_trace,0);
	m_trace->open("waveform.vcd");
	while(sc_time_stamp() < 20 && !contextp->gotFinish()){
		int a = rand() & 1;
		int b = rand() & 1;
		top->a = a;
		top->b = b;
		top->eval();
		printf("a=%d, b = %d, f = %d\n", a, b, top->f);
		assert(top->f == a ^ b);
		m_trace->dump(sc_time);
		sc_time++;
	} 
	m_trace->close();
	delete top;
	return 0;
}
