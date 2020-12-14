using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace Sky.Common
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class CommonResourceDictionary : ResourceDictionary
    {
        public CommonResourceDictionary()
        {
            InitializeComponent();
        }
    }
}