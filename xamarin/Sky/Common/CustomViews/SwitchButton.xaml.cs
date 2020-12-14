
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace Sky.Common.CustomViews
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class SwitchButton : ContentView
    {
        public delegate void SwitchPressedDelegate(object sender, EventArgs e);
        public event SwitchPressedDelegate OnSwitchPressed;
        public SwitchButton()
        {
            InitializeComponent();
        }

        private void SwitchPressed(object sender, EventArgs e)
        {
            OnSwitchPressed?.Invoke(this, e);
        }
    }
}