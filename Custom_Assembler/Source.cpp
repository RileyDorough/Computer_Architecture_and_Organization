#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
//#include <iomanip>

std::string readInstructions(std::ifstream& inputStream);

int main() {
	std::string outputFile = "data.out";
	std::string inputFile = "prog.s";
	std::ifstream inputStream;
	std::string finalOutput{"v2.0 raw\n4*0 "};
	inputStream.open(inputFile);

	while (!inputStream.eof())
	{
		finalOutput += readInstructions(inputStream);
	}
	inputStream.close();

	std::ofstream outStream;
	outStream.open(outputFile);
	outStream << finalOutput << std::endl;
	outStream.close();

	return 0;
}

std::string readInstructions(std::ifstream &inputStream) {
	std::string opcodes[13] = {"","LDX","LDY","LDA","ADC","SEC","STA","BCS","CLC","TAX","STX","JMP","STA"};
	std::string singleObjOutput;
	std::string tmpOpcode;
	int tmpVal;
	int hexConvertedOpcode;

	inputStream >> tmpOpcode;
	inputStream >> tmpVal;
	   
	bool inbounds = true;
	for (int i=0; i < 13 && inbounds; i++)
	{
		if (tmpOpcode == opcodes[i])
		{
			hexConvertedOpcode = i;
			// Check for absolute addressing STA
			if (tmpOpcode == "STA" && tmpVal != 0)
			{
				hexConvertedOpcode = 12;
			}
		}
	}

	std::stringstream convertToHex;
	convertToHex << std::hex << hexConvertedOpcode;
	singleObjOutput += convertToHex.str() += " ";
	convertToHex.str("");
	convertToHex << std::hex << tmpVal << " ";
	singleObjOutput += convertToHex.str();
	return singleObjOutput;
}