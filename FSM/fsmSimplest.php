<?php

//state base class 
abstract class States
{
     public $stateName;

		function __construct($state)
	{
		$this->stateName=$state;
	}
		abstract function execute();
}


//transition class 
class Transitions 
{
	public $transitionName;
	public $toState;

	function __construct($transition,$toState)
	{
		$this->transitionName=$transition;
		$this->toState=$toState;
	}

	function execute(){
       echo "Executing Transition ".$this->transitionName."\n";
	}
}


/**
* implementation of fsm
*/
class SimplestFSM 
{
    public $states;
    public $transitions;
    private $currentState;
    private $currentTransition;

	function __construct()
	{
		$this->states=array();
		$this->transitions=array();
		$this->currentState = NULL;
		$this->currentTransition=NULL;
	}

	function setState($state){
		
        if(isset($this->states[$state]))
		$this->currentState = $this->states[$state];
	}

	function setTransition($transition){

		if(isset($this->transitions[$transition]))
		$this->currentTransition=$this->transitions[$transition];
	}

	function getState(){
		return $this->currentState;
	}

	function getTransition(){
		return $this->currentTransition;
	}

	function execute(){
		if($this->currentTransition){

			//execute the transition function
			$this->currentTransition->execute();
			//set the current state 
			$this->setState($this->currentTransition->toState);
            //make transition null
            $this->setTransition(NULL);
            //and execute the new state 
            $this->currentState->execute();
		}

	}
}

//class for switch on 
class On extends States
{
	function execute(){
		echo "State: ".$this->stateName." and machine switched on \n";
	}
}

//class for switch off 
class Off extends States
{
	function execute(){
		echo "State:".$this->stateName." and machine switched off \n";
	}
}

//lets see fsm in action 
 $fsm = new SimplestFSM();

 //set states for fsm
 $fsm->states["On"]=new On("On");
 $fsm->states["Off"]= new Off("Off");

//set transitions 
 $fsm->transitions["onToOff"]=new Transitions("onToOff","Off");
 $fsm->transitions["offToOn"]= new Transitions("offToOn","On");



//set initial values 
 $fsm->setState("On");
 $fsm->setTransition(NULL);

 $i=0;
while ($i<10) {  //to show case the transitions
	$randomNumber=rand(0,1);

    //if nuber is 1 then only change the state of machine
	if($randomNumber){
		
		//current state is on 
        if($fsm->getState()->stateName=="On"){
           $fsm->setTransition("onToOff");
        }
        else{ //current state is off
             $fsm->setTransition("offToOn");
        }
	}
	$fsm->execute(); //alwasy execute machine function 
	$i++;
	}
?>