using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace Sky.Intro
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class InitialPage : ContentPage
    {
        public InitialPage()
        {
            NavigationPage.SetHasNavigationBar(this, false);
            InitializeComponent();
        }

        private void ButtonPressed_SignUp(object sender, EventArgs e)
        {
            Application.Current.MainPage.Navigation.PushAsync(new SignUpPage());
        }

        private void ButtonPressed_LogIn(object sender, EventArgs e)
        {
            Application.Current.MainPage.Navigation.PushAsync(new LoginPage());
        }
    }
}