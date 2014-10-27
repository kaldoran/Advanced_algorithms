#! /usr/bin/perl

use strict;
use warnings;
use XML::LibXML;

#############################################################
#####					VARIABLE						#####
#############################################################

my $XML_Repository	= "./xml/";
my $DATA_Repository = "./donnee/data";
my $donnee = "./donnee/";
my @XML_files;
my @DATA_files;
my $XML_file;
my $parser 		= XML::LibXML->new();
my $i=0;


#############################################################
#####						MAIN						#####
#############################################################

#list all XML files in $XML_Repository
opendir(REP, $XML_Repository ) or die "impossible d'ouvrir le repertoir $XML_Repository!\n";
	@XML_files=readdir(REP);
close(REP);

#remove old data files present in $DATA_Repository
opendir(REP, $donnee ) or die "impossible d'ouvrir le repertoir $DATA_Repository!\n";
	@DATA_files=readdir(REP);
	
	foreach my $_ (@DATA_files)
	{
		unlink $donnee.$_;
	}
close(REP);

#for all XML files, converte to data files
foreach $XML_file(@XML_files)
{
	if($XML_file=~ m/.*.xml/)
	{
		convert_XML_to_Data(join("",$XML_Repository,$XML_file),$i++);
	}
}
print "Done.\n";


#############################################################
#####			DECLARATION OF FUNCTIONS				#####
#############################################################

#this function creates data files with XML files input
sub convert_XML_to_Data
{
	my ($XML_file,$current_data_File) = @_; #read some parameters
	my $tree = $parser->parse_file($XML_file); #parse XML file
	my $root = $tree->getDocumentElement;

	my $node_number = $root->getElementsByTagName('name');
	$node_number =~ s/[a-zA-Z]*//;

	my @vertices = $root->getElementsByTagName('vertex'); #collect all vertex in XML file
	my $current_vertex=0;
	my $data_file =$DATA_Repository.$current_data_File;#name of data file

	print "Editing $XML_file-->data$current_data_File...";

	open(FILE, ">$data_file") or die "ERROR $!\n"; #create data file
	
	print(FILE "\$$node_number\$\n"); #writing number of node at top of file
	foreach my $vertex (@vertices)  #for all vertices
	{
		my @edges = $vertex->getElementsByTagName('edge'); #get all edges
		my $number_adj_edges=@edges;
		print(FILE "- $number_adj_edges\@$current_vertex");
		foreach my $edge (@edges)
		{ 	
			my $neighbor_vertex = $edge->getFirstChild->getData; #get vertex number
			my $att = $edge->getAttribute("cost"); #get scientific writing cost
			my @split_att = split(/e\+/,$att);
			my $cost=$split_att[0]*10**$split_att[1]; #converte scientific writing cost to integer cost

			print (FILE "$neighbor_vertex#$cost\n"); #edit
		}

		print (FILE "\n");
		$current_vertex++;
	}
	close(FILE);
	print "\n";
}