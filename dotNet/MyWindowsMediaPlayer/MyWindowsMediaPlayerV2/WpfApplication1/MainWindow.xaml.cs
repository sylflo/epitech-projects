using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Collections.ObjectModel;

namespace MyWindowsMediaPlayerV2
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private CoreSong core;
        public MainWindow()
        {
            InitializeComponent();
            this.DataContext = this;
            this.core = new CoreSong(this.player);

            this.button_previous.Click += new RoutedEventHandler(previous);
            this.button_next.Click += new RoutedEventHandler(next);
            this.button_play.Click += new RoutedEventHandler(play);
            this.button_stop.Click += new RoutedEventHandler(stop);
            this.button_delete.Click += new RoutedEventHandler(remove);
            this.button_add.Click += new RoutedEventHandler(add);
        }

        void stop(object sender, RoutedEventArgs e)
        {
            this.core.Stop();
        }

        void play(object sender, RoutedEventArgs e)
        {
            this.core.Play();
        }

        void next(object sender, RoutedEventArgs e)
        {
            this.core.Next();
        }

        void previous(object sender, RoutedEventArgs e)
        {
            this.core.Previous();
        }

        void remove(object sender, RoutedEventArgs e)
        {
            this.core.RemoveSong();
        }

        void add(object sender, RoutedEventArgs e)
        {
            System.Windows.Forms.OpenFileDialog dialog = new System.Windows.Forms.OpenFileDialog();
            dialog.Multiselect = true;
            System.Windows.Forms.DialogResult result = dialog.ShowDialog();
            if (result == System.Windows.Forms.DialogResult.OK)
            {
                foreach (string filename in dialog.FileNames)
                {
                    if (System.IO.File.Exists(filename))
                    {
                        this.core.AddSong(filename);
                    }
                }
            }
        }

        public ObservableCollection<Song> Songs
        {
            get { return this.core.Songs; }
        }
        }
    }
