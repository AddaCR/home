using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Text;

namespace Sky.Tab4_Favorites.ViewModel
{
    public class TabBarViewModel : INotifyPropertyChanged
    {
        private int columnSelected;
        public int ColumnSelected
        {
            get { return columnSelected; }
            set { columnSelected = value; OnPropertyChanged(); }
        }

        public event PropertyChangedEventHandler PropertyChanged;
        void OnPropertyChanged([CallerMemberName] string name = "")
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(name));
        }
    }
}
