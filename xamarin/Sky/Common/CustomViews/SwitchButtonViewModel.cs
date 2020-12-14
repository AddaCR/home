using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Runtime.CompilerServices;
using System.Text;

namespace Sky.Common.CustomViews
{
    public class SwitchButtonViewModel : INotifyPropertyChanged
    {
        private string Source_toggled_on = "";
        private string Source_toggled_off = "";
        private bool State;

        public SwitchButtonViewModel(string view_enabled, string view_disabled, bool initial_state)
        {
            State = initial_state;
            Source_toggled_on = view_enabled;
            Source_toggled_off = view_disabled;
        }

        public event PropertyChangedEventHandler PropertyChanged;

        public string ImageSource => State? Source_toggled_on : Source_toggled_off;


        public void Toggle()
        {
            System.Diagnostics.Debug.WriteLine("OnButtonToggled");
            State = !State;
            OnPropertyChanged(nameof(ImageSource));
        }

        void OnPropertyChanged([CallerMemberName] string name = "")
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(name));
        }
    }
}
