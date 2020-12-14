using Sky.Common.CustomViews;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace Sky.Tab4_Favorites.CustomContentView
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class TabSettings_ContentView : ContentView
    {
        SwitchButtonViewModel viewModel_fb = new SwitchButtonViewModel("common_switch_enabled.png", "common_switch_disabled.png", false);
        SwitchButtonViewModel viewModel_tw = new SwitchButtonViewModel("common_switch_enabled.png", "common_switch_disabled.png", false);
        public TabSettings_ContentView()
        {
            InitializeComponent();

            SwitchButtonFacebook.BindingContext = viewModel_fb;
            SwitchButtonFacebook.OnSwitchPressed += SwitchPressedFacebook;

            SwitchButtonTwitter.BindingContext = viewModel_tw;
            SwitchButtonTwitter.OnSwitchPressed += SwitchPressedTwitter;
        }

        private void SwitchPressedFacebook(object sender, EventArgs e)
        {
            viewModel_fb.Toggle();
        }
        private void SwitchPressedTwitter(object sender, EventArgs e)
        {
            viewModel_tw.Toggle();
        }
    }
}