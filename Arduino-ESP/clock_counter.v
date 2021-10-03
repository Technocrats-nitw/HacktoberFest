/*Create a set of counters suitable for use as a 12-hour clock (with am/pm indicator). 
Your counters are clocked by a fast-running clk, with a pulse on ena whenever your 
clock should increment (i.e., once per second).
reset resets the clock to 12:00 AM. pm is 0 for AM and 1 for PM. hh, mm, and ss 
are two BCD (Binary-Coded Decimal) digits each for hours (01-12), minutes (00-59), 
and seconds (00-59). Reset has higher priority than enable, and can occur even when not enabled. */

//Question source - HDL Bits

//By Swastik Khuntia
module top_module(
    input clk,
    input reset,
    input ena,
    output pm,
    output [7:0] hh,
    output [7:0] mm,
    output [7:0] ss); 
	
    reg[7:0] hha, mma, ssa;
    always @(posedge clk) begin
        if (reset) begin
            ssa <= 8'd0;
            mma <= 8'd0;
            hha <= 8'd12;
            pm <= 1'b0;
        end
           else if (ena) begin
               if (ssa == 8'd59) begin
                    ssa <= 8'd0;
                   if ( mma == 8'd59) begin
                    mma <= 8'd0;
                       if (hha == 8'd11)
                           pm <= ~pm;
                       if (hha == 8'd12) begin
                            hha <= 8'd1;
                            //pm <= ~pm;
                        end
                        else
                            hha <= hha + 1'd1;
                            end
                   else
                       mma <= mma + 1'd1;
                end
                else
                    ssa <= ssa + 8'd1;
        end
    end
 //HEX to BCD conversion
    assign hh[3:0] = hha % 10;
    assign hh[7:4] = (hha / 10) % 10;
    assign ss[3:0] = ssa % 10;
    assign ss[7:4] = (ssa / 10) % 10;
    assign mm[3:0] = mma % 10;
    assign mm[7:4] = (mma / 10) % 10;
endmodule