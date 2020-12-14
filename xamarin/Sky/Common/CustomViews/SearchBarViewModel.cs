using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Text;

namespace Sky.Common.CustomViews
{
    public class SearchBarViewModel : INotifyPropertyChanged
    {
        public SearchBarViewModel(string text = "")
        {
            searchText = text;
        }
        private string searchText;
        public string SearchBarText
        {
            get { return searchText; } 
            set { searchText = value; OnPropertyChanged(); }
        }

        public event PropertyChangedEventHandler PropertyChanged;


        void OnPropertyChanged([CallerMemberName] string name = "")
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(name));
        }
    }
}
