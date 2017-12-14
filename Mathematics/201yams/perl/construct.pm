#!/usr/bin/perl -w

package _yams;

sub	new
{
    my ($class, $d1, $d2, $d3, $d4, $d5, $name, $first, $second, $app) = @_;

    my $this =
    {
	d1 => $d1,
	d2 => $d2,
	d3 => $d3,
	d4 => $d4,
	d5 => $d5,
	name => $name,
	first => $first,
	second => $second,
	app => $app
    };
    bless($this, $class);
    
    return ($this);
}

1;
