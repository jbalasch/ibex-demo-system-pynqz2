module gfmul_8
(
    input [7:0] a_i,
    input [7:0] b_i,

    output [7:0] result_o
);

  logic [14:0] temp;

  assign temp[14] = a_i[7] & b_i[7];
  assign temp[13] = a_i[7] & b_i[6] ^ a_i[6] & b_i[7];
  assign temp[12] = a_i[7] & b_i[5] ^ a_i[6] & b_i[6] ^ a_i[5] & b_i[7];
  assign temp[11] = a_i[7] & b_i[4] ^ a_i[6] & b_i[5] ^ a_i[5] & b_i[6] ^ a_i[4] & b_i[7];
  assign temp[10] = a_i[7] & b_i[3] ^ a_i[6] & b_i[4] ^ a_i[5] & b_i[5] ^ a_i[4] & b_i[6] ^ a_i[3] & b_i[7];
  assign temp[9]  = a_i[7] & b_i[2] ^ a_i[6] & b_i[3] ^ a_i[5] & b_i[4] ^ a_i[4] & b_i[5] ^ a_i[3] & b_i[6] ^ a_i[2] & b_i[7];
  assign temp[8]  = a_i[7] & b_i[1] ^ a_i[6] & b_i[2] ^ a_i[5] & b_i[3] ^ a_i[4] & b_i[4] ^ a_i[3] & b_i[5] ^ a_i[2] & b_i[6] ^ a_i[1] & b_i[7];
  assign temp[7]  = a_i[7] & b_i[0] ^ a_i[6] & b_i[1] ^ a_i[5] & b_i[2] ^ a_i[4] & b_i[3] ^ a_i[3] & b_i[4] ^ a_i[2] & b_i[5] ^ a_i[1] & b_i[6] ^ a_i[0] & b_i[7];
  assign temp[6]  = a_i[6] & b_i[0] ^ a_i[5] & b_i[1] ^ a_i[4] & b_i[2] ^ a_i[3] & b_i[3] ^ a_i[2] & b_i[4] ^ a_i[1] & b_i[5] ^ a_i[0] & b_i[6];
  assign temp[5]  = a_i[5] & b_i[0] ^ a_i[4] & b_i[1] ^ a_i[3] & b_i[2] ^ a_i[2] & b_i[3] ^ a_i[1] & b_i[4] ^ a_i[0] & b_i[5];
  assign temp[4]  = a_i[4] & b_i[0] ^ a_i[3] & b_i[1] ^ a_i[2] & b_i[2] ^ a_i[1] & b_i[3] ^ a_i[0] & b_i[4];
  assign temp[3]  = a_i[3] & b_i[0] ^ a_i[2] & b_i[1] ^ a_i[1] & b_i[2] ^ a_i[0] & b_i[3];
  assign temp[2]  = a_i[2] & b_i[0] ^ a_i[1] & b_i[1] ^ a_i[0] & b_i[2];
  assign temp[1]  = a_i[1] & b_i[0] ^ a_i[0] & b_i[1];
  assign temp[0]  = a_i[0] & b_i[0];
  
  assign result_o[7] = temp[7] ^ temp[11] ^ temp[12] ^ temp[14];
  assign result_o[6] = temp[6] ^ temp[10] ^ temp[11] ^ temp[13];
  assign result_o[5] = temp[5] ^ temp[9]  ^ temp[10] ^ temp[12];
  assign result_o[4] = temp[4] ^ temp[8]  ^ temp[9]  ^ temp[11] ^ temp[14];
  assign result_o[3] = temp[3] ^ temp[8]  ^ temp[10] ^ temp[11] ^ temp[12] ^ temp[13] ^ temp[14];
  assign result_o[2] = temp[2] ^ temp[9]  ^ temp[10] ^ temp[13];
  assign result_o[1] = temp[1] ^ temp[8]  ^ temp[9]  ^ temp[12] ^ temp[14];
  assign result_o[0] = temp[0] ^ temp[8]  ^ temp[12] ^ temp[13];
  
endmodule 
