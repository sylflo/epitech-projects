using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections.ObjectModel;
using System.Windows.Controls;

namespace MyWindowsMediaPlayerV2
{
    public class CoreSong
    {
        private bool playing = false;
        private bool pause = false;
        private MediaElement mediaplayer;
        private ObservableCollection<Song> songs;
        public int songListed { get; set; }
        public CoreSong(MediaElement mediaElement)
        {
            this.songs = new ObservableCollection<Song>();
            this.mediaplayer = mediaElement;
        }

        public ObservableCollection<Song> Songs
        {
            get { return this.songs; }
        }

        public void AddSong(string path)
        {
            if (System.IO.File.Exists(path))
            {
                this.songs.Add(new Song(System.IO.Path.GetFileNameWithoutExtension(path), path));
            }
        }

        public void RemoveSong()
        {
            if (this.songs.Count > this.songListed)
            {
                this.songs.RemoveAt(this.songListed);
            }
        }

        public void Play()
        {
            if (!this.pause && this.playing)
            {
                this.Pause();
            }
            else
            {
                if (!this.pause)
                {
                    Song current = this.Songs[this.songListed];
                    this.mediaplayer.Source = new Uri(current.Path);
                }
                this.playing = true;
                this.pause = false;
                this.mediaplayer.Play();
            }
        }

        public void Stop()
        {
            this.mediaplayer.Stop();
            this.pause = false;
            this.playing = false;
        }

        public void Pause()
        {
            this.playing = false;
            this.pause = true;
            this.mediaplayer.Pause();
        }

        public void Next()
        {
            this.songListed++;
            this.Stop();
            if (this.songListed >= this.songs.Count)
            {
                this.songListed = 0;
            }
            this.Play();
        }

        public void Previous()
        {
            this.songListed--;
            this.Stop();
            if (this.songListed < 0)
            {
                this.songListed = this.songs.Count - 1;
            }
            this.Play();
        }
    }
}
