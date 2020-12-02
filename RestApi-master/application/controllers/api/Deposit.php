<?php
defined('BASEPATH') OR exit('No direct script access allowed');

// This can be removed if you use __autoload() in config.php OR use Modular Extensions
/** @noinspection PhpIncludeInspection */

require APPPATH . 'libraries/REST_Controller.php';

class Deposit extends REST_Controller 
{

    
    function __construct()
    {
        //enable cors
        header('Access-Control-Allow-Origin: *');
        header("Access-Control-Allow-Methods: GET, POST, OPTIONS, PUT, DELETE");
        // Construct the parent class
        parent::__construct();

        $this->load->model('Deposit_model');
    }




    public function deposit_put()
    {

        
        $update_data=array(
        'acc'=> $this->put('acc'),
        'amount'=>$this->put('amount')
        );
        $result=$this->Deposit_model->update_deposit($update_data);

        if($result)
        {
        $message = [
            'data_array'        =>  $update_data,
             'message' => 'Added money to account'
            ];

            $this->set_response($message, REST_Controller::HTTP_CREATED); // CREATED (201) being the HTTP response code
        }
        else
        {
             // Set the response and exit
            $this->response([
                'status' => FALSE,
                'message' => 'Can not add money to client'
            ], REST_Controller::HTTP_CONFLICT); // CAN NOT CREATE (409) being the HTTP response code
        }
    }   

}

