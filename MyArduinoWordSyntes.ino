#include <Wtv020sd16p.h> //библиотека работы модуля WTV020

int resetPin = 7; //подключение ножки сброса модуля к пину 7
int clockPin = 8; //подключение ножки тактового сигнала модуля к пину 8
int dataPin = 5;  //подключение информационного вывода модуля к пину 5
int busyPin = 4;  //подключение вывода "занятости" модуля к пину 4

//String toSayWord = "privet men8 zavut pa3a";

int defDelayLetter = 220;
int delayBetwinWord = 100;
int delayBetwinFrases = 350;

Wtv020sd16p wtv020sd16p(resetPin, clockPin, dataPin, busyPin); //объявляем модулю, куда что подключили

void setup()
{
	Serial.begin(57600);

	wtv020sd16p.reset();

	Serial.println("Reset sound module. Wait...");

	delay(1000);

	Serial.println("...finished.");
	Serial.println("Type something text, using latin letter for russian word, after press enter.");
	Serial.println("Have fun!)");
	Serial.println("");
}

void loop()
{

	if (Serial.available())
	{
		String toSayWord = Serial.readString();

		for (int i = 0; i < toSayWord.length(); i++)
		{
			String letter = (String)toSayWord[i];
			letter.toLowerCase();

			if (letter == "a") { wtv020sd16p.asyncPlayVoice(1); Serial.print("a"); delay(300); } //а
			if (letter == "b") { wtv020sd16p.asyncPlayVoice(2); Serial.print("b"); delay(350); } //б
			if (letter == "v") { wtv020sd16p.asyncPlayVoice(3); Serial.print("v"); delay(400); } //в
			if (letter == "g") { wtv020sd16p.asyncPlayVoice(4); Serial.print("g"); delay(defDelayLetter); }//г
			if (letter == "d") { wtv020sd16p.asyncPlayVoice(5); Serial.print("d"); delay(350); } //д
			if (letter == "e") { wtv020sd16p.asyncPlayVoice(6); Serial.print("e"); delay(defDelayLetter); }//е
			if (letter == "y")
			{
				//Serial.println(++i);
				if ((String)toSayWord[++i] == "o")
				{
					wtv020sd16p.asyncPlayVoice(7); Serial.print("yo"); delay(defDelayLetter); //ё
				}
				else if ((String)toSayWord[i] == "i")
				{
					//Serial.println("1");
					wtv020sd16p.asyncPlayVoice(28); Serial.print("yi"); delay(defDelayLetter); //ы
				}
				else if ((String)toSayWord[i] == "e")
				{
					wtv020sd16p.asyncPlayVoice(29); Serial.print("ye"); delay(450); //э
				}
				else if ((String)toSayWord[i] == "u")
				{
					wtv020sd16p.asyncPlayVoice(30); Serial.print("yu"); delay(350); //ю
				}
				else if ((String)toSayWord[i] == "a")
				{
					wtv020sd16p.asyncPlayVoice(31); Serial.print("ya"); delay(450); //я
				}
				else
				{
					wtv020sd16p.asyncPlayVoice(11); Serial.print("y"); delay(defDelayLetter); //й
					--i;
				}
			}
			if (letter == "j") { wtv020sd16p.asyncPlayVoice(8); Serial.print("j"); delay(defDelayLetter); }//ж
			if (letter == "z") { wtv020sd16p.asyncPlayVoice(9); Serial.print("z"); delay(300); }//з
			if (letter == "i") { wtv020sd16p.asyncPlayVoice(10); Serial.print("i"); delay(300); }//и
			//if (letter == "y") { wtv020sd16p.asyncPlayVoice(11); Serial.print("y"); delay(defDelayLetter); }//й
			if (letter == "k") { wtv020sd16p.asyncPlayVoice(12); Serial.print("k"); delay(defDelayLetter); }//к
			if (letter == "l") { wtv020sd16p.asyncPlayVoice(13); Serial.print("l"); delay(300); }//л
			if (letter == "m") { wtv020sd16p.asyncPlayVoice(14); Serial.print("m"); delay(defDelayLetter); }//м
			if (letter == "n") { wtv020sd16p.asyncPlayVoice(15); Serial.print("n"); delay(350); }//н
			if (letter == "o") { wtv020sd16p.asyncPlayVoice(16); Serial.print("o"); delay(350); }//о
			if (letter == "p") { wtv020sd16p.asyncPlayVoice(17); Serial.print("p"); delay(300); }//п
			if (letter == "r") { wtv020sd16p.asyncPlayVoice(18); Serial.print("r"); delay(350); }//р
			if (letter == "s")
			{
				if ((String)toSayWord[++i] == "h")
				{
					if ((String)toSayWord[++i] == "c" && (String)toSayWord[++i] == "h")
					{
						wtv020sd16p.asyncPlayVoice(27); Serial.print("shch"); delay(450); //щ
					}
					else
					{
						wtv020sd16p.asyncPlayVoice(26); Serial.print("sh"); delay(430); //ш
						--i;
					}
				}
				else
				{
					wtv020sd16p.asyncPlayVoice(19); Serial.print("s"); delay(350); //с
					--i;
				}
			}
			if (letter == "t") { wtv020sd16p.asyncPlayVoice(20); Serial.print("t"); delay(defDelayLetter); }//т
			if (letter == "u") { wtv020sd16p.asyncPlayVoice(21); Serial.print("u"); delay(defDelayLetter); }//у
			if (letter == "f") { wtv020sd16p.asyncPlayVoice(22); Serial.print("f"); delay(defDelayLetter); }//ф
			if (letter == "h") { wtv020sd16p.asyncPlayVoice(23); Serial.print("h"); delay(300); }//х
			if (letter == "c")
			{
				if ((String)toSayWord[++i] == "h")
				{
					wtv020sd16p.asyncPlayVoice(25); Serial.print("ch"); delay(430); //ч
				}
				else
				{
					wtv020sd16p.asyncPlayVoice(24); Serial.print("c"); delay(450); //ц
					--i;
				}
				//if (letter == "4") { wtv020sd16p.asyncPlayVoice(25); Serial.print("4"); delay(defDelayLetter); }//ч
				//if (letter == "6") { wtv020sd16p.asyncPlayVoice(26); Serial.print("6"); delay(defDelayLetter); }//ш
				//if (letter == "5") { wtv020sd16p.asyncPlayVoice(27); Serial.print("7"); delay(defDelayLetter); }//щ
				//if (letter == "3") { wtv020sd16p.asyncPlayVoice(28); Serial.print("3"); delay(defDelayLetter); }//ы
				//if (letter == "7") { wtv020sd16p.asyncPlayVoice(29); Serial.print("7"); delay(defDelayLetter); }//э
				//if (letter == "8") { wtv020sd16p.asyncPlayVoice(30); Serial.print("8"); delay(defDelayLetter); }//ю
				//if (letter == "9") { wtv020sd16p.asyncPlayVoice(31); Serial.print("9"); delay(defDelayLetter); }//я
			}
			if (letter == " ") { Serial.print(" "); delay(delayBetwinWord); } //пробел
			if (letter == ".") { Serial.print("."); delay(delayBetwinFrases); }
			if (letter == "-") Serial.print("-");
			if (letter == ",") Serial.print(",");
			if (letter == "!") Serial.print("!");
			if (letter == "?") Serial.print("?");
		}
		Serial.println(" <OK>");
	}
}
