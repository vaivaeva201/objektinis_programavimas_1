while (true)
        {
        cin >> pasirinkimas;
            if (cin.fail() || cin.peek() != '\n' || pasirinkimas < 1 || pasirinkimas > 4)
            {
                cout << "Prašau įveskite vieną iš duotų variantų ";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else
            {
                break;               
            }
        }