module a (
    input   wire        clka,
    input   wire        clkb,
    input   wire        rstna,
    input   wire        rstnb,
    input   wire        a,

    output  reg         b
);

reg     flag;

reg     flagb;
always @(posedge clka or negedge rstna) begin
    if(!rstna)
        flag <= 'd0;
    else if(a)
        flag <= ~flag;
    else
        flag <= flag;
end

always @(posedge clkb or negedge rstnb) begin
    if(!rstnb)
        flagb <= 'd0;
    else
        flagb <= flag;
end

reg     reg1;
reg     reg2;
reg     reg3;
always @(posedge clkb or negedge rstnb) begin
    if(!rstnb)begin
        reg1 <= 'd0;
        reg2 <= 'd0;
        reg3 <= 'd0;
    end
    else begin
        reg1 <= flagb;
        reg2 <= reg1;
        reg3 <= reg2;
    end
end

wire    o;
assign  o = reg2 ^ reg3;

endmodule //a