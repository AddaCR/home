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
    public partial class BackButton : ContentView
    {
        public BackButton()
        {
            InitializeComponent();
        }

        private void OnButtonPress_Back(object sender, EventArgs e)
        {
            System.Diagnostics.Debug.WriteLine("OnButtonPress_Back");
            Navigation.PopAsync();
        }
    }
}