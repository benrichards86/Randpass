// Randpass.cpp : main project file.

#include "stdafx.h"
#include "Form1.h"

using namespace Randpass;

System::Void Form1::bGenerate_Click(System::Object^  sender, System::EventArgs^  e) {
	((System::Windows::Forms::Button^)sender)->Enabled = false;
				 
	System::Random rand;

	tbNewPass->Text = "";

    int numOptions = (cbCustom->Checked) + (cbSymbols->Checked) + (cbNumbers->Checked) + !(rbNoLetters->Checked);

    for (int i = 0; i < numPassLen->Value; i++) {
		int n = rand.Next(0, 100 * numOptions);
		switch(n / 100) {
        case 0:
			if (!rbNoLetters->Checked) {
				int v;
				if (rbMixed->Checked)
					v = (int)((n % 100) / 100.0f * 52);
				else
					v = (int)((n % 100) / 100.0f * 26);

				if (rbLowercase->Checked)
					tbNewPass->Text += wchar_t(v + 'a');
				else if (rbUppercase->Checked)
					tbNewPass->Text += wchar_t(v + 'A');
				else {
					if (v < 26)
						tbNewPass->Text += wchar_t(v + 'A');
					else
						tbNewPass->Text += wchar_t(v + 'a' - 26);
				}

				break;
			}
			// If checked, fall through...
		case 1:
			if (cbNumbers->Checked) {
				int v = (int)((n % 100) / 100.0f * 10);
				tbNewPass->Text += wchar_t(v + '0');
				break;
			}
			// If not checked, fall through...
		case 2:
			if (cbSymbols->Checked) {
				int v = (int)((n % 100) / 100.0f * 32);
				if (v < 15)
					tbNewPass->Text += wchar_t(v + '!');
                else if (v < 22)
                    tbNewPass->Text += wchar_t(v - 15 + ':');
                else if (v < 28)
                    tbNewPass->Text += wchar_t(v - 22 + '[');
                else
                    tbNewPass->Text += wchar_t(v - 28 + '{');
				break;
			}
			// If not checked, fall through...
		case 3:
            if (cbCustom->Checked) {
				ArrayList ^chars = gcnew ArrayList(lbChars->Items);
                            
				int i = (int)((n % 100) / 100.0f * chars->Count);
				tbNewPass->Text += chars[i];
				break;
            }
		default:
            // Something went horribly wrong if we get here
			MessageBox::Show("There are no character sets enabled to generate a password!");
			((System::Windows::Forms::Button^)sender)->Enabled = true;
			return;
		}
					 
	}

    lbPasswords->Items->Insert(0, tbNewPass->Text);
    lbPasswords->SelectedIndex = 0;
                 
	((System::Windows::Forms::Button^)sender)->Enabled = true;
}

System::Void Form1::bAddChar_Click(System::Object^  sender, System::EventArgs^  e) {
    if (!System::String::IsNullOrEmpty(tbAddChar->Text)) {
        lbChars->BeginUpdate();
		System::String^ notUsed = addCustomChars(tbAddChar->Text);
		lbChars->EndUpdate();
        tbAddChar->Text = notUsed;
        cbCustom->Enabled = true;
    }
}

System::Void Form1::bRemove_Click(System::Object^  sender, System::EventArgs^  e) {
    int currIndex = 0;
    while (currIndex < lbChars->Items->Count) {
        Char curr = (Char)(lbChars->Items[currIndex]);
        if (lbChars->SelectedItems->Contains(curr))
            lbChars->Items->Remove(curr);
        else
            currIndex += 1;
    }

    cbCustom->Enabled = (lbChars->Items->Count > 0);
    cbCustom->Checked = cbCustom->Checked && cbCustom->Enabled;
}

System::Void Form1::saveOptionsDialog_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	pin_ptr<const wchar_t> filename = PtrToStringChars(saveOptionsDialog->FileName);
	saveOptions(filename);
}

System::Void Form1::openOptionsDialog_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	pin_ptr<const wchar_t> filename = PtrToStringChars(openOptionsDialog->FileName);
	loadOptions(filename);
}

System::Void Form1::loadOptions(const wchar_t *filename) {
	Options opt;
	std::ifstream in(filename, std::ios::binary);
	in.read((char*)&opt, sizeof(opt));
	in.close();

	switch(opt.letters) {
	case Lcase:
		rbLowercase->Checked = true;
		rbUppercase->Checked = false;
		rbMixed->Checked = false;
		rbNoLetters->Checked = false;
		break;
	case Ucase:
		rbLowercase->Checked = false;
		rbUppercase->Checked = true;
		rbMixed->Checked = false;
		rbNoLetters->Checked = false;
		break;
	case Mixed:
		rbLowercase->Checked = false;
		rbUppercase->Checked = false;
		rbMixed->Checked = true;
		rbNoLetters->Checked = false;
		break;
	case None:
		rbLowercase->Checked = false;
		rbUppercase->Checked = false;
		rbMixed->Checked = false;
		rbNoLetters->Checked = true;
		break;
	default:
		break;
	};

	cbNumbers->Checked = opt.numbers;
	cbSymbols->Checked = opt.symbols;
	cbCustom->Checked = opt.custom;
	numPassLen->Value = opt.length;
	
	System::String^ text = gcnew System::String(opt.customChars);
	addCustomChars(text);
}

System::Void Form1::saveOptions(const wchar_t *filename) {
	// Gather options:
	Options opt;
			 
	if (rbLowercase->Checked)
		opt.letters = Lcase;
	else if (rbUppercase->Checked)
		opt.letters = Ucase;
	else if (rbMixed->Checked)
		opt.letters = Mixed;
	else
		opt.letters = None;

	opt.numbers = cbNumbers->Checked;
	opt.symbols = cbSymbols->Checked;
	opt.custom = cbCustom->Checked;
	opt.length = numPassLen->Value;

	ArrayList ^chars = gcnew ArrayList(lbChars->Items);
	for (int i = 0; i < 256; i++) {
		if (i < lbChars->Items->Count)
			opt.customChars[i] = (wchar_t)chars[i];
		else
			opt.customChars[i] = '\0';
	}

	// Write to file
	std::ofstream out(filename, std::ios::binary);
	out.write((char*)&opt, sizeof(opt));
	out.close();
}

System::Void Form1::saveListDialog_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	savePasswords(saveListDialog->FileName);
}

System::Void Form1::savePasswords(String^ filename) {
	System::IO::StreamWriter^ out = gcnew System::IO::StreamWriter(filename);
	for (int i = 0; i < lbPasswords->Items->Count; i++) {
		out->WriteLine((String^)lbPasswords->Items[i]);
	}
	out->Close();
}

System::Void Form1::openListDialog_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	loadPasswords(openListDialog->FileName);
}

System::Void Form1::loadPasswords(String^ filename) {
	System::IO::StreamReader ^in = gcnew System::IO::StreamReader(filename);
	while (!in->EndOfStream) {
		lbPasswords->Items->Add(in->ReadLine());
	}
	in->Close();
}

System::String^ Form1::addCustomChars(System::String^ charStr){
	System::String^ notUsed = "";
    CharEnumerator ^iter = charStr->GetEnumerator();
    while (iter->MoveNext()) {
        wchar_t curr = iter->Current;
		if (lbChars->Items->Count < 256) {
			if (!lbChars->Items->Contains(curr)) {
				lbChars->Items->Add(curr);
			}
		}
		else {
			notUsed += curr;
		}
    }

	return notUsed;
}

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew Form1());
	return 0;
}
