<?php
 
defined('BASEPATH') OR exit('No direct script access allowed');
 
require APPPATH . 'libraries/REST_Controller.php';
 
class Transactions extends REST_Controller 
{
 
    function __construct()
    {
        //enable cors
        header('Access-Control-Allow-Origin: *');
        header("Access-Control-Allow-Methods: GET, POST, OPTIONS, PUT, DELETE");
        // Construct the parent class
        parent::__construct();
 
        $this->load->model('Transactions_model');
    }
 
    public function transactions_get()
    {
    // book from a data store e.g. database  
    
        $this->load->model('Transactions_model');
 
        $client_id = $this->get('client_id');
        $accType = $this->get('accType');
        /*$call_procedure= "CALL get_acc_events($client_id, $accType)";
        $data=array('CID'=>$client_id, 'AType'=>$accType);
        $query=$this->db->query($call_procedure, $data);*/
        $result=$this->Transactions_model->events($client_id, $accType);
        echo json_encode($result);
 
    }
}