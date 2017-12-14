#!/usr/bin/perl -w

use	QtCore4;
use	QtGui4;

package _yams;

sub	paire
{

}

sub	brelan
{

}

sub	carre
{

}

sub	full
{

}

sub	yams
{

}

sub	CallOperations
{
    my	$this = shift;
    my	$window = Qt::Widget();
    my	$name_combi = Qt::Label("Combinaison", $window);

    $window->setFixedSize(400, 100);
    $name_combi->move(2, 50);
    $window->show();
}

1 ;
