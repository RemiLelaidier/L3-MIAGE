package code39;

public class Code39{
	
	static String[] tabEncode;
	
	public Code39(){
		tabEncode = new String[44];
		tabEncode[0] = "100001001";
		tabEncode[1] = "001001001";
		tabEncode[2] = "101001000";
		tabEncode[3] = "000011001";
		tabEncode[4] = "100011000";
		tabEncode[5] = "001011000";
		tabEncode[6] = "000001101";
		tabEncode[7] = "100001100";
		tabEncode[8] = "001001100";
		tabEncode[9] = "000011100";
		tabEncode[10] = "100000011";
		tabEncode[11] = "001000011";
		tabEncode[12] = "101000010";
		tabEncode[13] = "000010011";
		tabEncode[14] = "100010010";
		tabEncode[15] = "001010010";
		tabEncode[16] = "000000111";
		tabEncode[17] = "100000110";
		tabEncode[18] = "001000110";
		tabEncode[19] = "000010110";
		tabEncode[20] = "110000001";
		tabEncode[21] = "011000001";
		tabEncode[22] = "111000000";
		tabEncode[23] = "010010001";
		tabEncode[24] = "110010000";
		tabEncode[25] = "011010000";
		tabEncode[26] = "000110100";
		tabEncode[27] = "100100001";
		tabEncode[28] = "001100001";
		tabEncode[29] = "101100000";
		tabEncode[30] = "000110001";
		tabEncode[31] = "100110000";
		tabEncode[32] = "001110000";
		tabEncode[33] = "000100101";
		tabEncode[34] = "100100100";
		tabEncode[35] = "001100100";
		tabEncode[36] = "011000100";
		tabEncode[37] = "010000101";
		tabEncode[38] = "010101000";
		tabEncode[39] = "000101010";
		tabEncode[40] = "110000100";
		tabEncode[41] = "010100010";
		tabEncode[42] = "010001010";
		tabEncode[43] = "010010100";
	}
	
	public String encodeCarac(char entry){
		if(entry == 'A')
			return tabEncode[0];
		else if(entry == 'B')
			return tabEncode[1];
		else if(entry == 'C')
			return tabEncode[2];
		else if(entry == 'D')
			return tabEncode[3];
		else if(entry == 'E')
			return tabEncode[4];
		else if(entry == 'F')
			return tabEncode[5];
		else if(entry == 'G')
			return tabEncode[6];
		else if(entry == 'H')
			return tabEncode[7];
		else if(entry == 'I')
			return tabEncode[8];
		else if(entry == 'J')
			return tabEncode[9];
		else if(entry == 'K')
			return tabEncode[10];
		else if(entry == 'L')
			return tabEncode[11];
		else if(entry == 'M')
			return tabEncode[12];
		else if(entry == 'N')
			return tabEncode[13];
		else if(entry == 'O')
			return tabEncode[14];
		else if(entry == 'P')
			return tabEncode[15];
		else if(entry == 'Q')
			return tabEncode[16];
		else if(entry == 'R')
			return tabEncode[17];
		else if(entry == 'S')
			return tabEncode[18];
		else if(entry == 'T')
			return tabEncode[19];
		else if(entry == 'U')
			return tabEncode[20];
		else if(entry == 'V')
			return tabEncode[21];
		else if(entry == 'W')
			return tabEncode[22];
		else if(entry == 'X')
			return tabEncode[23];
		else if(entry == 'Y')
			return tabEncode[24];
		else if(entry == 'Z')
			return tabEncode[25];
		else if(entry == '0')
			return tabEncode[26];
		else if(entry == '1')
			return tabEncode[27];
		else if(entry == '2')
			return tabEncode[28];
		else if(entry == '3')
			return tabEncode[29];
		else if(entry == '4')
			return tabEncode[30];
		else if(entry == '5')
			return tabEncode[31];
		else if(entry == '6')
			return tabEncode[32];
		else if(entry == '7')
			return tabEncode[33];
		else if(entry == '8')
			return tabEncode[34];
		else if(entry == '9')
			return tabEncode[35];
		else if(entry == ' ')
			return tabEncode[36];
		else if(entry == '-')
			return tabEncode[37];
		else if(entry == '$')
			return tabEncode[38];
		else if(entry == '%')
			return tabEncode[39];
		else if(entry == '.')
			return tabEncode[40];
		else if(entry == '/')
			return tabEncode[41];
		else if(entry == '+')
			return tabEncode[42];
		else if(entry == '*')
			return tabEncode[43];
		return tabEncode[43];
	}
	
	public String encodeMess(String s_entry){
		String res = new String();
		res = this.encodeCarac('*');
		res = res + "0";
		char[] caracs = s_entry.toCharArray();
		for(char carac : caracs){
			res = res + this.encodeCarac(carac);
			res = res + "0";
		}
		res = res + this.encodeCarac('*');
		return res;
	}
}

