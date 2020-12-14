using Sky.Common;
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
    public partial class LoginPage : ContentPage
    {
        public LoginPage()
        {
            NavigationPage.SetHasNavigationBar(this, false);
            InitializeComponent();
        }

        private void ButtonPressed_Login(object sender, EventArgs e)
        {
            Application.Current.MainPage.Navigation.PushAsync(new MainPage());
        }

        private void ButtonPressed_ForgotPassword(object sender, EventArgs e)
        {
            PopupHelper.ShowAlertDialog("LoginPage", "Button pressed - Forgot password", this);
        }

        private void ButtonPressed_SignUp(object sender, EventArgs e)
        {
            Application.Current.MainPage.Navigation.PopAsync();
            Application.Current.MainPage.Navigation.PushAsync(new SignUpPage());
        }
    }
}