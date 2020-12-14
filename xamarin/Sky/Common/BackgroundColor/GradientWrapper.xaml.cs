using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

using Xamarin.Forms;
using Xamarin.Forms.Xaml;

namespace Sky.Common.BackgroundColor
{
    [XamlCompilation(XamlCompilationOptions.Compile)]
    public partial class GradientWrapper : ContentView
    {
        public static readonly BindableProperty AngleProperty = BindableProperty.Create("Angle", typeof(double), typeof(GradientWrapper), 0.0);
        public static readonly BindableProperty StartColorProperty = BindableProperty.Create("StartColor", typeof(Color), typeof(GradientWrapper), Color.Black);
        public static readonly BindableProperty EndColorProperty = BindableProperty.Create("EndColor", typeof(Color), typeof(GradientWrapper), Color.Black);

        public double Angle
        {
            get => (double)GetValue(AngleProperty);
            set => SetValue(AngleProperty, value);
        }
        public Color StartColor
        {
            get => (Color)GetValue(StartColorProperty);
            set => SetValue(StartColorProperty, value);
        }
        public Color EndColor
        {
            get => (Color)GetValue(EndColorProperty);
            set => SetValue(EndColorProperty, value);
        }


        public GradientWrapper()
        {
            InitializeComponent();
        }


        public GradientWrapper(Color startColor, Color endColor, double angle = 90)
        {
            StartColor = startColor;
            EndColor = endColor;
            Angle = angle;
            InitializeComponent();
        }
    }

}